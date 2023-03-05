/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** cercle_shape
*/

#include "../../../include/my.h"

void draw_circle_pixel(struct paint_t *paint, sfColor color, int x, int y)
{
    if (!check_pixel(paint->pos.y, paint->pos.x, y, paint))
        return;
    sfImage_setPixel(paint->image, paint->pos.x + x, paint->pos.y - y, color);
    sfImage_setPixel(paint->image, paint->pos.x + y, paint->pos.y - x, color);
    sfImage_setPixel(paint->image, paint->pos.x - x, paint->pos.y - y, color);
    sfImage_setPixel(paint->image, paint->pos.x - y, paint->pos.y - x, color);
    sfImage_setPixel(paint->image, paint->pos.x + y, paint->pos.y + x, color);
    sfImage_setPixel(paint->image, paint->pos.x - y, paint->pos.y + x, color);
    sfImage_setPixel(paint->image, paint->pos.x - x, paint->pos.y + y, color);
    sfImage_setPixel(paint->image, paint->pos.x + x, paint->pos.y + y, color);
}

static void call_circle_pixel(struct paint_t *paint, sfColor color, int radius)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    while (x <= y) {
        draw_circle_pixel(paint, color, x, y);
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void draw_circle(struct paint_t *paint, int radius)
{
    int x = 0;
    radius /= 1.5;
    int y = radius;
    int d = 3 - 2 * radius;
    sfColor color = paint->color_pick;
    pixel(paint, paint->pos, radius + (radius / 2.6));
    while (radius > 0) {
        call_circle_pixel(paint, color, radius);
        radius--;
    }
}
