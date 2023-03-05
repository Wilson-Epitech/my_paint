/*
** MY_PAINT PROJECT, 2023
** test
** File description:
** print_pixel
*/

#include "../../../include/my.h"

int paint_win(sfEvent event, struct paint_t *paint)
{
    sfVector2f pos = paint->pos;
    sfVector2f size_win = paint->size_win;
    float size = paint->size_pen / 10;
    if (paint->gomme == 1)
        size = paint->size_eraser / 5;
    if (sfMouse_isButtonPressed(0) && pos.x < size_win.x
    && pos.y < size_win.y && pos.x > 0 && pos.y > 100) {
        square_cercle(paint, pos, size);
    }
    sfTexture *board_tex = sfTexture_createFromImage(paint->image, NULL);
    sfSprite *board = sfSprite_create();
    sfSprite_setTexture(board, board_tex, 0);
    sfRenderWindow_drawSprite(paint->window, board, NULL);
    sfTexture_destroy(board_tex);
    sfSprite_destroy(board);
    if (pos.x < size_win.x
    && pos.y < size_win.y && pos.x > 0 && pos.y > 100)
        hitbox_pixel(paint, pos, size);
}
