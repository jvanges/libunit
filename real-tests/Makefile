# **************************************************************************** #
#                                                                              #
#   Makefile de la routine de tests reels (15 tests sur la libft)              #
#   Regle 'test' exigee par le sujet : compile PUIS execute le binaire.        #
#                                                                              #
# **************************************************************************** #

NAME		= real_tests

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBUNIT_DIR	= ../framework
LIBFT_DIR	= ../libft
INCLUDES	= -I$(LIBUNIT_DIR)/includes -I$(LIBFT_DIR)

SRCS		= main.c \
			  strlen/00_launcher.c \
			  strlen/01_basic_test.c \
			  strlen/02_empty_test.c \
			  strlen/03_spaces_test.c \
			  strlen/04_special_test.c \
			  strlen/05_long_test.c \
			  atoi/00_launcher.c \
			  atoi/01_basic_test.c \
			  atoi/02_negative_test.c \
			  atoi/03_whitespace_test.c \
			  atoi/04_trailing_junk_test.c \
			  atoi/05_multiple_signs_test.c \
			  atoi/06_zero_test.c \
			  split/00_launcher.c \
			  split/01_basic_test.c \
			  split/02_multi_sep_test.c \
			  split/03_empty_string_test.c \
			  split/04_only_sep_test.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBUNIT_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBUNIT_DIR)/libunit.a $(LIBFT_DIR)/libft.a \
		-o $(NAME)

test: all
	./$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re
