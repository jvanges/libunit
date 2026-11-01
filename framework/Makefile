# **************************************************************************** #
#                                                                              #
#   Makefile du micro-framework libunit -> libunit.a                           #
#                                                                              #
# **************************************************************************** #

NAME		= libunit.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes

SRCS		= src/load_test.c \
			  src/clear_tests.c \
			  src/exec_test.c \
			  src/launch_tests.c \
			  src/print_result.c \
			  src/utils.c

SRCS_BONUS	= src_bonus/exec_test_bonus.c \
			  src_bonus/launch_tests_bonus.c \
			  src_bonus/print_result_bonus.c \
			  src_bonus/log_bonus.c

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# La regle bonus ajoute les fonctionnalites interdites a la partie
# obligatoire (couleurs, timeout, signaux etendus, journal .log, stdout)
# dans LA MEME bibliotheque statique, comme le demande le sujet.
bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
