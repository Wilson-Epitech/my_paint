/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** button
*/

#include "../../include/my.h"

void rect_boutton(struct button_s *boutton, struct paint_t *paint, int i)
{
    int x = boutton->def_button[i][0];
    int y = boutton->def_button[i][1];
    int h = boutton->def_button[i][2];
    int l = boutton->def_button[i][3];
    sfRectangleShape_setSize(boutton->rect,
    get_position(l, h));
    sfRectangleShape_setPosition(boutton->rect,
    get_position(x, y));
    sfRectangleShape_setFillColor(boutton->rect, boutton->color);
    sfRectangleShape_setOutlineThickness(boutton->rect,
    boutton->def_button[i][4]);
    sfRectangleShape_setOutlineColor(boutton->rect, boutton->outcolor);
    sfRenderWindow_drawRectangleShape(paint->window, boutton->rect, 0);
}

int switch_press(int i)
{
    if (i == 1)
        return 0;
    if (i == 0)
        return 1;
}

int is_touch(struct button_s *boutton,
    struct paint_t *paint,sfEvent event, int i)
{
    sfVector2f pos = paint->pos;
    sfVector2u windowSize = sfRenderWindow_getSize(paint->window);
    int h = boutton->def_button[i][2];
    int l = boutton->def_button[i][3];
    int press = boutton->def_button[i][5];
    if (pos.x <= boutton->def_button[i][0] + l &&
    pos.x >= boutton->def_button[i][0] &&
    pos.y <= boutton->def_button[i][1] + h &&
    pos.y >= boutton->def_button[i][1]) {
        if (sfMouse_isButtonPressed(0)) {
            boutton->def_button[i][5] = switch_press(press);
            return 2;
        }
        return 1;
    }
    return 0;
}

void button(struct button_s *boutton,
    struct paint_t *paint, sfEvent event, int i)
{
    boutton->color = sfColor_fromRGBA(255, 255, 255, 200);
    int press = is_touch(boutton, paint, event, i);
    if (press == 0 && boutton->def_button[i][5] == 0) {
        boutton->def_button[i][4] = 1;
        boutton->outcolor = sfBlack;
    } else if (press == 1){
        boutton->def_button[i][4] = 2;
        boutton->outcolor = sfBlack;
        boutton->color = sfColor_fromRGBA(255, 255, 255, 255);
    }
    if (boutton->def_button[i][5] == 1) {
        boutton->color = sfColor_fromRGBA(0, 255, 50, 255);
    }
    rect_boutton(boutton, paint, i);
}
