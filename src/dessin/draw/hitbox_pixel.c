/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** hitbox_pixel
*/

#include "../../../include/my.h"

static void hitbox_square(struct pen_t *pen, struct paint_t *paint, float size)
{
    sfColor border = pen->color_pick;
    sfVector2f pos = paint->pos;
    int size_border = 0;
    if (pen->gomme == 0) {
        sfSprite_setPosition(paint->pen,
        get_position(pos.x - (8 - size / 2), pos.y - (40 + size / 2)));
        sfRenderWindow_drawSprite(paint->window, paint->pen, 0);
    }
    if (pen->gomme == 1) {
        border = sfBlack;
        size_border = 1;
    }
    sfRectangleShape *pixel = sfRectangleShape_create();
    sfRectangleShape_setSize(pixel, get_position(size, size));
    sfRectangleShape_setFillColor(pixel, pen->color_pick);
    sfRectangleShape_setPosition(pixel,
    get_position(pos.x - size / 2, pos.y - size / 2));
    sfRectangleShape_setOutlineThickness(pixel,size_border);
    sfRectangleShape_setOutlineColor(pixel, border);
    sfRenderWindow_drawRectangleShape(paint->window, pixel, 0);
}

static void hitbox_cercle(struct paint_t *paint, struct pen_t *pen, float size)
{
    sfColor border = pen->color_pick;
    sfVector2f pos = paint->pos;
    int size_border = 0;
    if (pen->gomme == 0) {
        sfSprite_setPosition(paint->pen,
        get_position(pos.x - (8 - size / 2), pos.y - (40 + size / 2)));
        sfRenderWindow_drawSprite(paint->window, paint->pen, 0);
    }
    if (pen->gomme == 1) {
        border = sfBlack;
        size_border = 1;
    }
    sfCircleShape *pixel = sfCircleShape_create();
    sfCircleShape_setRadius(pixel, size / 1.5);
    sfCircleShape_setFillColor(pixel, pen->color_pick);
    sfCircleShape_setPosition(pixel,
    get_position(pos.x - size / 1.5, pos.y - size / 1.5));
    sfCircleShape_setOutlineThickness(pixel,size_border);
    sfCircleShape_setOutlineColor(pixel, border);
    sfRenderWindow_drawCircleShape(paint->window, pixel, 0);
}

void hitbox_pixel(struct paint_t *paint, struct pen_t *pen, float size)
{
    sfVector2f pos = paint->pos;
    int cercle = pen->cercle_pen;
    if (pen->gomme == 1) {
        cercle = pen->cercle_eraser;
    }
    if (cercle == 1)
        hitbox_cercle(paint, pen, size);
    else
        hitbox_square(pen, paint, size);
}
