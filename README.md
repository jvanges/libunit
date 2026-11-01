# libunit — Micro-framework de tests unitaires en C (Rush 42)

Micro-framework écrit comme **bibliothèque statique `libunit.a`**, capable
d'exécuter une série de tests les uns après les autres **sans interruption**,
même si l'un d'eux segfaulte : chaque test tourne dans son propre processus.

## Arborescence

```
libunit/
├── framework/          le micro-framework -> libunit.a
│   ├── includes/       libunit.h (+ libunit_bonus.h)
│   ├── src/            partie obligatoire
│   └── src_bonus/      couleurs, timeout, signaux étendus, .log, stdout
├── libft/              copie de la libft (utilisée par real-tests)
├── tests/              routine de démonstration exigée par le sujet
│   ├── mandatory/      vrais tests OK / KO / SIGSEGV / SIGBUS
│   └── bonus/          vrais tests pour chaque fonctionnalité bonus
└── real-tests/         15 vrais tests sur la libft (strlen, atoi, split)
```

## Utilisation

```sh
make -C framework            # compile libunit.a
make -C tests test           # compile + lance la routine obligatoire
make -C tests bonus          # idem avec les bonus (journal BONUS.log)
make -C real-tests test      # compile + lance les 15 tests réels
make test                    # tout, depuis la racine
```

## Fonctionnement

1. `load_test(&list, "nom", &fonction)` empile un test dans une liste
   chaînée (ajout en fin → exécution dans l'ordre de chargement).
2. `launch_tests(&list, "FONCTION")` parcourt la liste : pour chaque test,
   `fork()` crée un fils qui exécute la fonction puis `exit()` avec sa
   valeur de retour.
3. Le père récupère le statut avec `wait()` :
   - `exit(0)` → `[OK]`, autre code → `[KO]`
   - mort par signal → `[SEGV]`, `[BUSERR]`, etc.
   Un crash tue donc le fils, jamais le framework ni la routine.
4. Bilan `X/Y tests checked`, liste entièrement libérée (zéro fuite).
   Retour : `0` si tout a réussi, `-1` sinon (imposé par le sujet).

## Format de sortie

```
FONCTION: Nom du test : [STATUT]
X/Y tests checked
```

## Bonus implémentés

| Bonus | Mécanisme (choix justifiés) |
|---|---|
| Couleurs | séquences ANSI émises via `write()` (vert/rouge/magenta) |
| Timeout | `alarm(TEST_TIMEOUT)` dans le fils → SIGALRM, pas de `kill()` (interdit), pas de zombie (le père fait toujours `wait()`) |
| stdout detourné | `open("/dev/null")` + `dup2()` dans le fils : la fonction testée peut écrire sans polluer le rapport |
| Signaux | SIGABRT, SIGFPE, SIGPIPE, SIGILL en plus de SIGSEGV/SIGBUS |
| Journal | `<fonction>.log` écrit via `open/write/close` : non bufferisé, exploitable même après un crash |

## Routine de tests

- `tests/mandatory` : OK, KO, **vrai** SIGSEGV (écriture à `NULL`),
  **vrai** SIGBUS (lecture `mmap()` au-delà de la fin d'un fichier vide).
- `tests/bonus` : SIGABRT (`abort()`), SIGFPE (division entière par 0),
  SIGPIPE (tube fermé), SIGILL (`__builtin_trap()`), TIMEOUT (boucle
  infinie), STDOUT (écriture capturée).
- `real-tests` : 15 tests sur `ft_strlen` (×5), `ft_atoi` (×6, comparés à la
  vraie `atoi()` de la libc pour rester impartial) et `ft_split` (×4).
