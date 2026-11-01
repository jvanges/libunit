# **************************************************************************** #
#                                                                              #
#   Makefile de la routine de tests obligatoire + bonus                        #
#   Regle 'test' exigee par le sujet : compile PUIS execute le binaire.        #
#                                                                              #
# **************************************************************************** #

NAME		= unit_tests
NAME_BONUS	= unit_tests_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBUNIT_DIR	= ../framework
INCLUDES	= -I$(LIBUNIT_DIR)/includes

SRCS		= main.c \
			  mandatory/00_launcher.c \
			  mandatory/01_ok_test.c \
			  mandatory/02_ko_test.c \
			  mandatory/03_sigsegv_test.c \
			  mandatory/04_sigbus_test.c

SRCS_BONUS	= main_bonus.c \
			  mandatory/00_launcher.c \
			  mandatory/01_ok_test.c \
			  mandatory/02_ko_test.c \
			  mandatory/03_sigsegv_test.c \
			  mandatory/04_sigbus_test.c \
			  bonus/00_launcher.c \
			  bonus/01_sigabrt_test.c \
			  bonus/02_sigfpe_test.c \
			  bonus/03_sigpipe_test.c \
			  bonus/04_sigill_test.c \
			  bonus/05_timeout_test.c \
			  bonus/06_stdout_test.c

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBUNIT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBUNIT_DIR)/libunit.a -o $(NAME)

test: all
	./$(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C $(LIBUNIT_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBUNIT_DIR)/libunit.a -o $(NAME_BONUS)

bonus: $(NAME_BONUS)
	./$(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) BONUS.log

re: fclean all

.PHONY: all test bonus clean fclean re
