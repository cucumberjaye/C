NAME = so_long

SRC = srcs/pars.c	srcs/so_long.c	srcs/errors.c	srcs/free_fun.c		getnl/get_next_line.c		getnl/get_next_line_utils.c\
	srcs/textures.c	srcs/steps.c	printf/printf.c 			printf/flags_1.c 	printf/flags_2.c		srcs/itoa.c\

SRC2 = srcs/bonus.c		srcs/so_long_bonus.c 	srcs/steps_bonus.c	srcs/pars.c		srcs/errors.c	srcs/free_fun.c	getnl/get_next_line.c\
	getnl/get_next_line_utils.c	srcs/steps_2.c	printf/printf.c	printf/flags_1.c 	printf/flags_2.c		srcs/itoa.c\
	srcs/textures.c	srcs/steps.c\

OBJ = $(SRC:.c=.o)

OBJB = $(SRC2:.c=.o)

FLAGS = cc -Wall -Wextra -Werror

MLX = mlx_linux/Makefile.gen

LIB = -L ./mlx_linux -lmlx -lXext -lX11 -lm -lbsd

all: $(MLX) $(NAME)

$(MLX):
	@make -s -C mlx_linux

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) $(LIB) -o $(NAME)

bonus: $(MLX) $(OBJB)
	$(FLAGS) $(OBJB) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJB)

fclean:	clean
	@rm -rf $(NAME)

re:	fclean all
