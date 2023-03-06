/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** square_cercle
*/

#include "../../../include/my.h"

int check_pixel(float y,float x, float size, struct paint_t *paint)
{
    if (y - size <= 0 || y + size >= paint->size_win.y)
        return 0;
    if (x - size <= 0 || x + size >= paint->size_win.x)
        return 0;
    return 1;
}

void pixel(struct paint_t *paint, sfVector2f pos, float size)
{
    int x = pos.x;
    int y = pos.y;
    size /= 2;
    y -= size;
    while (y < pos.y + size) {
        for (x = pos.x - size; x < pos.x + size &&
        check_pixel(pos.y, pos.x, size, paint); x++) {
            sfImage_setPixel(paint->image, x, y, paint->color_pick);
        }
        y++;
    }
}

void square_cercle(struct paint_t *paint, struct pen_t *pen, float size)
{
    sfVector2f pos = paint->pos;
    int cercle = pen->cercle_pen;
    if (pen->gomme == 1) {
        cercle = pen->cercle_eraser;
    }
    if (cercle == 1)
        draw_circle(paint, size);
    else
        pixel(paint, pos, size);
}
