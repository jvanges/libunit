# **************************************************************************** #
#                                                                              #
#   Makefile de confort a la racine : delegue aux sous-Makefiles.              #
#   Le sujet exige un Makefile dans framework/, tests/ et real-tests/ ;        #
#   celui-ci permet simplement de tout piloter depuis la racine.               #
#                                                                              #
# **************************************************************************** #

all:
	$(MAKE) -C framework
	$(MAKE) -C libft

test:
	$(MAKE) -C tests test
	$(MAKE) -C real-tests test

bonus:
	$(MAKE) -C tests bonus

clean:
	$(MAKE) -C framework clean
	$(MAKE) -C tests clean
	$(MAKE) -C real-tests clean
	$(MAKE) -C libft clean

fclean: clean
	$(MAKE) -C framework fclean
	$(MAKE) -C tests fclean
	$(MAKE) -C real-tests fclean
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all test bonus clean fclean re
