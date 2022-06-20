NAME = pipex

CC = cc 

FLAGS = -Wall -Werror -Wextra -o

SRC = pipex.c	help_fun/ft_split.c		help_fun/func.c		child_fun.c\

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all