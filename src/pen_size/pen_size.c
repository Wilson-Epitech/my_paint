/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** pen_size
*/

#include "../../include/my.h"

void size_select(struct paint_t *paint)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfColor color = sfBlue;
    int x = 620 + paint->size_pen;
    float y = 52;
    int l = 5;
    int h = 20;
    sfRectangleShape_setSize(rect, get_position(l, h));
    sfRectangleShape_setPosition(rect, get_position(x, y));
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRenderWindow_drawRectangleShape(paint->window, rect, 0);
}

void rect_slider(struct paint_t *paint)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    int x = 600;
    int y = 37;
    int l = 400;
    int h = 50;
    sfColor color = sfWhite;
    for (int i = 0; i < 2; i++) {
        sfRectangleShape_setSize(rect, get_position(l, h));
        sfRectangleShape_setPosition(rect, get_position(x, y));
        if (i == 1)
            color = sfColor_fromRGB(0, 0, 0);
        sfRectangleShape_setFillColor(rect, color);
        sfRectangleShape_setOutlineThickness(rect, 1);
        sfRectangleShape_setOutlineColor(rect, sfBlack);
        sfRenderWindow_drawRectangleShape(paint->window, rect, 0);
        l -= 41;
        h = 5;
        x += 21;
        y += 23;
    }
}

void pen_size(struct paint_t *paint, sfEvent event)
{
    rect_slider(paint);
    sfVector2f pos = paint->pos;
    if (pos.x <= 975 && pos.x >= 600 &&
    pos.y <= 87 && pos.y >= 37 &&
    sfMouse_isButtonPressed(0)) {
        paint->size_pen = pos.x - 620;
        if (paint->size_pen < 0)
            paint->size_pen = 1;
    }
    size_select(paint);
}
