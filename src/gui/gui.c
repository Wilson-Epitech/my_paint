/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** gui
*/

#include "../../include/my.h"

sfRectangleShape *create_back(struct paint_t *paint, int hauteur, sfColor color)
{
    sfRectangleShape_setSize(paint->back,
    get_position(1920, hauteur));
    sfRectangleShape_setFillColor(paint->back, color);
    sfRenderWindow_drawRectangleShape(paint->window, paint->back, 0);
}

void select_color(struct paint_t *paint, int x, int y, sfColor color)
{
    sfRectangleShape_setSize(paint->color_block,
    get_position(20, 20));
    sfRectangleShape_setPosition(paint->color_block, get_position(x, y));
    sfRectangleShape_setFillColor(paint->color_block, color);
    sfRenderWindow_drawRectangleShape(paint->window, paint->color_block, 0);
}

void gui(struct paint_t *paint, sfEvent event)
{
    int x = 1100;
    int y = 50;
    sfVector2i pos = sfMouse_getPositionRenderWindow(paint->window);

    create_back(paint,100, sfColor_fromRGBA(147, 147, 255, 255));
    create_back(paint,25, sfColor_fromRGBA(147, 147, 147, 255));

    for (int i = 0; i < 6; i++) {
        select_color(paint,x, y, color_pallet(i, paint, 1));
        if (pos.x <= x + 20 && pos.x >= x &&
        pos.y <= y + 20 && pos.y >= y &&
        event.type == sfEvtMouseButtonPressed) {
            create_back(paint,25, paint->color_pick);
            paint->color_pick = color_pallet(i, paint, 0);
        }
        x += 30;
    }
}
