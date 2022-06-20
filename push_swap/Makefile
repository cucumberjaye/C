NAME = push_swap

NAME2 = checker

SRC = 	srcs/push_swap.c		srcs/errors.c	srcs/pars.c		srcs/index.c\
		srcs/commands_1.c	srcs/commands_2.c	srcs/algorithm.c\
		srcs/score_a.c		srcs/score_b.c	srcs/help_func.c\
		srcs/score_b2.c		srcs/alg_help_func.c\

SRC2 =	gnl/get_next_line.c		gnl/get_next_line_utils.c	srcs/bonus.c\
		srcs/errors.c	srcs/pars.c		srcs/commands_1.c	srcs/bonus_commands.c\

M = Makefile

FLAGS = cc -Wall -Wextra -Werror -o

all: $(NAME) $(M) 

$(NAME):
	@$(MAKE) -C liba/ re
	$(FLAGS) $(NAME) $(SRC) -L liba/ -lft

$(NAME2):$(M) $(SRC2)
	$(FLAGS) $(NAME2) $(SRC2) -L liba/ -lft

bonus: $(NAME2)
	
clean:
	@$(MAKE) -C liba/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
	@$(MAKE) -C liba/ fclean

re: fclean all

.PHONY : all clean fclean re
