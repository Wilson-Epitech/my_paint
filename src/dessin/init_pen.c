/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** init_pen
*/

#include "../../include/my.h"

void init_pen(struct paint_t *paint, struct pen_t *pen)
{
    pen->color_pick = sfBlack;
    pen->id_color = 1;
    pen->gomme = 0;
    pen->size_pen = 350;
    pen->size_eraser = 100;
    pen->cercle_eraser = 1;
    pen->cercle_pen = 0;
}
