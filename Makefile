##
## MY_PAINT PROJECT, 2022
## hunter
## File description:
## Makefile
##

SRC	=	src/*.c	\
	src/color/*.c	\
	src/sprite/*.c	\
	src/pen_size/*.c	\
	src/bouton/*.c	\
	lib/*.c

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
