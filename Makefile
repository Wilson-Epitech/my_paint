##
## MY_PAINT PROJECT, 2022
## hunter
## File description:
## Makefile
##

SRC	=	src/*.c	\
	src/gui/*.c	\

OBJ	=	$(SRC/.c=.o)

NAME	=	my_paint

LIB	=	-lcsfml-system -lcsfml-graphics -lcsfml-audio -lcsfml-window

$(NAME):
	gcc $(SRC) $(LIB) -lm -o $(NAME)

all:	$(NAME) clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re:	fclean all

.PHONY:	$(NAME) all clean
