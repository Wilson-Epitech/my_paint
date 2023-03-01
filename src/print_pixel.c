/*
** MY_PAINT PROJECT, 2023
** test
** File description:
** print_pixel
*/

#include "../include/my.h"

int paint_win(sfEvent event, struct paint_t *paint)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(paint->window);
    sfVector2u size_win = sfRenderWindow_getSize(paint->window);
    size_win.y -= 100;
    if (sfMouse_isButtonPressed(0) && pos.x < size_win.x
    && pos.y < size_win.y) {
        sfImage_setPixel(paint->image, pos.x, pos.y, paint->color_pick);
    }
    sfTexture *board_tex = sfTexture_createFromImage(paint->image, NULL);
    sfSprite *board = sfSprite_create();
    sfSprite_setTexture(board, board_tex, 0);
    sfRenderWindow_drawSprite(paint->window, board, NULL);
    sfTexture_destroy(board_tex);
    sfSprite_destroy(board);
}
