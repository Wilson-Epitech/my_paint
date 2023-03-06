/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** color_select
*/

#include "../../../include/my.h"

sfRectangleShape *create_back(struct paint_t *paint, int h, sfColor color)
{
    sfRectangleShape_setSize(paint->back,
    get_position(1920, h));
    sfRectangleShape_setFillColor(paint->back, color);
    sfRenderWindow_drawRectangleShape(paint->window, paint->back, 0);
}

static void color_rect(struct paint_t *paint, int x, int y, sfColor color)
{
    sfRectangleShape_setSize(paint->color_block,
    get_position(20, 20));
    sfRectangleShape_setPosition(paint->color_block, get_position(x, y));
    sfRectangleShape_setFillColor(paint->color_block, color);
    sfRectangleShape_setOutlineThickness(paint->color_block, 1);
    if (paint->pos.x <= x + 20 && paint->pos.x >= x &&
    paint->pos.y <= y + 20 && paint->pos.y >= y) {
        sfRectangleShape_setOutlineColor(paint->color_block, sfWhite);
    } else {
        sfRectangleShape_setOutlineColor(paint->color_block, sfBlack);
    }
    sfRenderWindow_drawRectangleShape(paint->window, paint->color_block, 0);
}

static void select_gomme(struct paint_t *paint, sfEvent event)
{
    sfVector2f pos = paint->pos;
    int x = 1050 - 7;
    int y = 50 - (50 / 8);
    sfSprite_setPosition(paint->eraser,get_position(x, y));
    sfSprite_setScale(paint->eraser, get_position(0.07, 0.07));
    sfRenderWindow_drawSprite(paint->window, paint->eraser, 0);
    sfSprite_setScale(paint->eraser, get_position(0.1, 0.1));
    if (pos.x <= x + 33 && pos.x >= x &&
    pos.y <= y + 33 && pos.y >= y &&
    event.type == sfEvtMouseButtonPressed) {
        paint->color_pick = color_pallet(0, paint, 0);
    }
}

static void selected_color(struct paint_t *paint)
{
    sfRectangleShape_setSize(paint->color_block,
    get_position(40, 40));
    sfRectangleShape_setPosition(paint->color_block, get_position(1220, 60));
    sfRectangleShape_setFillColor(paint->color_block, paint->color_pick);
    sfRectangleShape_setOutlineThickness(paint->color_block, 1);
    sfRectangleShape_setOutlineColor(paint->color_block, sfBlack);
    sfRenderWindow_drawRectangleShape(paint->window, paint->color_block, 0);
}

void color_select(struct paint_t *paint, sfEvent event)
{
    int x = 1130;
    int y = 30;
    sfVector2f pos = paint->pos;

    create_back(paint,100, sfColor_fromRGBA(147, 147, 255, 255));
    create_back(paint,25, sfColor_fromRGBA(147, 147, 147, 255));
    select_gomme(paint, event);
    for (int i = 1; i < 8; i++) {
        color_rect(paint,x, y, color_pallet(i, paint, 1));
        if (pos.x <= x + 20 && pos.x >= x &&
        pos.y <= y + 20 && pos.y >= y &&
        event.type == sfEvtMouseButtonPressed) {
            paint->color_pick = color_pallet(i, paint, 0);
        }
        x += 30;
    }
}
