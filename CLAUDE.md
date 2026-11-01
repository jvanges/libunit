# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Projet

Rush 42 « libunit » : micro-framework de tests unitaires en C livré en bibliothèque statique `libunit.a`, plus deux routines de tests (`tests/` démonstration exigée par le sujet, `real-tests/` 15 tests réels sur la libft).

## Commandes

Depuis la racine (le Makefile racine délègue aux sous-Makefiles) :

```sh
make -C framework            # libunit.a (partie obligatoire)
make -C framework bonus      # ajoute les _bonus dans la MEME libunit.a
make -C tests test           # compile + exécute la routine obligatoire
make -C tests bonus          # idem avec les bonus, produit BONUS.log
make -C real-tests test      # compile + exécute les 15 tests réels
```

- La règle `test` **compile puis exécute** (exigence du sujet).
- ⚠️ `make test` termine en erreur 255 quand un test échoue : c'est **voulu** (le sujet impose que la routine renvoie -1 si au moins un test échoue). Ne pas « corriger » ce comportement.
- Pas de norminette installée sur cette machine ; vérifier la Norme manuellement (voir contraintes ci-dessous).
- Flags : `-Wall -Wextra -Werror`, jamais de `-O3` dans les règles par défaut.

## Architecture

Le cœur du framework (`framework/src/exec_test.c`) : chaque test est exécuté dans un **processus fils** (`fork()`). Le fils appelle la fonction de test puis `exit()` avec sa valeur de retour ; le père décode le statut via `wait()` :

- `exit(0)` → `ST_OK`, autre code → `ST_KO` (exit(-1) ressort tronqué à 255, toujours ≠ 0)
- signal → `ST_SEGV` / `ST_BUS` (obligatoire) ; bonus ajoute `ST_B_ABRT/FPE/PIPE/ILL/TIMEOUT` (codes à partir de 100 pour ne pas entrer en conflit avec `enum e_status`)

Un crash tue le fils, jamais la routine : c'est l'invariant central, ne jamais exécuter un test dans le processus parent.

Chaîne d'appel : *launcher* (`00_launcher.c`) → `load_test()` (ajout en **fin** de liste chaînée `t_unit_test` → ordre d'exécution = ordre de chargement) → `launch_tests()` → `exec_test()` + `print_result()` par test → `clear_tests()` (libération totale, zéro fuite imposée) → bilan `X/Y tests checked`, retour `0`/`-1`.

Le framework est volontairement **autonome** (pas de dépendance libft) : seules `malloc/free/exit/fork/wait/write` sont autorisées en partie obligatoire, d'où `lu_putstr`/`lu_putnbr`/`lu_dupstr` internes. La `libft/` copiée ne sert qu'à `real-tests/`.

### Bonus (`framework/src_bonus/`)

- Timeout : `alarm(TEST_TIMEOUT)` dans le fils → SIGALRM → `[TIMEOUT]`. Jamais `kill()` (interdit par le sujet), jamais de zombie (le père fait toujours `wait()`).
- stdout : le fils redirige sa sortie vers `/dev/null` (`open`+`dup2`) avant de lancer le test.
- Journal : `<fonction>.log` écrit via `open/write/close` **non bufferisé** (exploitable même après corruption mémoire d'un test suivant).

## Mini-norme du sujet pour les routines de tests

- Une seule fonction par fichier de test, prototype imposé `int f(void)` (0 = succès, -1 = échec).
- Noms de fichiers : préfixe numérique `NN_` = ordre d'exécution ; `00_*` = launcher.
- La limite des 25 lignes ne s'applique **pas** aux launchers ni aux mains des routines.
- Pour passer un test sous silence : commenter sa ligne `load_test()` ; pour une routine entière : commenter l'appel au launcher dans le main.
- Contrats de sortie : `[fonction]:[nom test] : [statut]` puis `X/Y tests checked`.

## Contraintes Norme observées

25 lignes/fonction, tabulations, ≤ 80 colonnes, une déclaration par ligne, **aucun commentaire dans le corps des fonctions** (les explications vont dans le bloc au-dessus de la fonction). Les fichiers bonus sont dans des fichiers distincts `_bonus.c/h` et une règle `bonus` (évaluation séparée mandatory/bonus).

## Astuces de tests de signaux (références pour écrire de nouveaux tests)

- SIGSEGV : écriture via pointeur `volatile` NULL
- SIGBUS : `mmap()` d'un fichier vide puis lecture au-delà de la fin
- SIGFPE : division entière par un `volatile int` nul
- SIGPIPE : `pipe()` + fermeture de l'extrémité lecture puis `write()`
- SIGILL : `__builtin_trap()`
