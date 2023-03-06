/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** init_struct
*/

#include "../include/my.h"

void position_boutton(struct button_s *boutton)
{
    boutton->rect = sfRectangleShape_create();
    boutton->def_button = malloc(sizeof(int *) * 4);
    int x = 10;
    for (int i = 0; i < 4; i++) {
        boutton->def_button[i] = malloc(sizeof(int) * 6);
        boutton->def_button[i][0] = x;
        boutton->def_button[i][1] = 25;
        boutton->def_button[i][2] = 50;
        boutton->def_button[i][3] = 100;
        boutton->def_button[i][4] = 1;
        boutton->def_button[i][5] = 0;
        x += 110;
    }
}

void init_struct(struct paint_t *paint, struct button_s *boutton)
{
    sfVideoMode mode = { 1366, 716 , 32 };
    paint->window = sfRenderWindow_create(mode, "my paint",
    sfResize | sfClose, NULL);
    paint->win_size = sfRenderWindow_getSize(paint->window);
    paint->back = sfRectangleShape_create();
    paint->color_block = sfRectangleShape_create();
    paint->color_pick = sfBlack;
    position_boutton(boutton);
    paint->image = sfImage_createFromColor(1367, 718, sfWhite);
    paint->gomme = 0;
    paint->size_pen = 20;
    paint->size_eraser = 60;
    paint->cercle_eraser = 1;
    paint->cercle_pen = 1;
    boutton->window = paint->window;
    set_pen(paint);
    set_eraser(paint);
}
