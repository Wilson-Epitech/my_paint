/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** all_draw
*/

#include "../../include/my.h"

void draw_all(struct paint_t *paint, sfEvent event, struct pen_t *pen)
{
    paint_win(event, paint, pen);
    color_select(paint, pen, event);
    pen_size(paint, pen, event);
}
