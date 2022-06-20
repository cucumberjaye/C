NAME = libftprintf.a

LIST = 		flags_1.c		flags_2.c		printf.c\
		
M = Makefile

OBJ = $(patsubst %.c,%.o,$(LIST))

D_FILES = $(patsubst %.c,%.d,$(LIST) $(LIST_B)) 

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c $(M)
	gcc $(FLAGS) -c $<  -o $@ -MD

include $(wildcard $(D_FILES))

clean :
	@rm -f $(OBJ) $(D_FILES)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean f clean re
