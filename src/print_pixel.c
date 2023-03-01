/*
** MY_PAINT PROJECT, 2023
** test
** File description:
** print_pixel
*/

#include "../include/my.h"

void pixel(sfEvent event, struct paint_t *paint, sfVector2i pos, int size)
{
    sfImage_setPixel(paint->image, pos.x, pos.y, paint->color_pick);
    int x = pos.x;
    int y = pos.y;
    y -= size;
    while (y < pos.y + size) {
        for (x = pos.x - size; x < pos.x + size; x++) {
            sfImage_setPixel(paint->image, x, y, paint->color_pick);
        }
        y++;
    }
}

int paint_win(sfEvent event, struct paint_t *paint)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(paint->window);
    sfVector2u size_win = sfRenderWindow_getSize(paint->window);
    size_win.y -= 100;
    if (sfMouse_isButtonPressed(0) && pos.x < size_win.x
    && pos.y < size_win.y) {
        if (paint->gomme == 1)
            pixel(event, paint, pos, 5);
        if (paint->gomme == 0)
            pixel(event, paint, pos, 2);
    }
    sfTexture *board_tex = sfTexture_createFromImage(paint->image, NULL);
    sfSprite *board = sfSprite_create();
    sfSprite_setTexture(board, board_tex, 0);
    sfRenderWindow_drawSprite(paint->window, board, NULL);
    sfTexture_destroy(board_tex);
    sfSprite_destroy(board);
}
