/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** struct_draw
*/

#ifndef STRUCT_DRAW_H_
    #define STRUCT_DRAW_H_

    #include "../include.h"

struct paint_t {
    sfRenderWindow *window;
    sfRectangleShape *back;
    sfRectangleShape *color_block;
    sfColor color_pick;
    sfVector2u win_size;
    sfImage *image;
    int gomme;
    sfSprite *pen;
    sfSprite *eraser;
    sfVector2f pos;
    sfVector2f size_win;
    float size_pen;
    float size_eraser;
    int cercle_pen;
    int cercle_eraser;
    int display_pixel;
};

#endif /* !STRUCT_DRAW_H_ */
