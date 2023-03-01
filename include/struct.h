/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include "include.h"

struct paint_t {
    sfRenderWindow *window;
    sfRectangleShape *back;
    sfRectangleShape *color_block;
    sfColor color_pick;
    sfVector2u win_size;
    sfImage *image;
};

struct button_s {
    sfRectangleShape *rect;
    int **def_button;
    sfColor outcolor;
    sfColor color;
    sfVector2f dimention;
    sfVector2f posi;
};

#endif /* !STRUCT_H_ */
