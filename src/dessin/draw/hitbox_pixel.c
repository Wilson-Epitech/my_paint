/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** hitbox_pixel
*/

#include "../../../include/my.h"

static void hitbox_square(sfVector2f pos, struct paint_t *paint, float size)
{
    sfColor border = paint->color_pick;
    int size_border = 0;
    if (paint->gomme == 0) {
        sfSprite_setPosition(paint->pen,
        get_position(pos.x - (8 - size / 2), pos.y - (40 + size / 2)));
        sfRenderWindow_drawSprite(paint->window, paint->pen, 0);
    }
    if (paint->gomme == 1) {
        border = sfBlack;
        size_border = 1;
    }
    sfRectangleShape *pixel = sfRectangleShape_create();
    sfRectangleShape_setSize(pixel, get_position(size, size));
    sfRectangleShape_setFillColor(pixel, paint->color_pick);
    sfRectangleShape_setPosition(pixel,
    get_position(pos.x - size / 2, pos.y - size / 2));
    sfRectangleShape_setOutlineThickness(pixel,size_border);
    sfRectangleShape_setOutlineColor(pixel, border);
    sfRenderWindow_drawRectangleShape(paint->window, pixel, 0);
}

static void hitbox_cercle(struct paint_t *paint, sfVector2f pos, float size)
{
    sfColor border = paint->color_pick;
    int size_border = 0;
    if (paint->gomme == 0) {
        sfSprite_setPosition(paint->pen,
        get_position(pos.x - (8 - size / 2), pos.y - (40 + size / 2)));
        sfRenderWindow_drawSprite(paint->window, paint->pen, 0);
    }
    if (paint->gomme == 1) {
        border = sfBlack;
        size_border = 1;
    }
    sfCircleShape *pixel = sfCircleShape_create();
    sfCircleShape_setRadius(pixel, size / 1.5);
    sfCircleShape_setFillColor(pixel, paint->color_pick);
    sfCircleShape_setPosition(pixel,
    get_position(pos.x - size / 1.5, pos.y - size / 1.5));
    sfCircleShape_setOutlineThickness(pixel,size_border);
    sfCircleShape_setOutlineColor(pixel, border);
    sfRenderWindow_drawCircleShape(paint->window, pixel, 0);
}

void hitbox_pixel(struct paint_t *paint, sfVector2f pos, float size)
{
    int cercle = paint->cercle_pen;
    if (paint->gomme == 1) {
        cercle = paint->cercle_eraser;
    }
    if (cercle == 1)
        hitbox_cercle(paint, pos, size);
    else
        hitbox_square(pos, paint, size);
}
