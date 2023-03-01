/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** utils
*/

#include "../include/my.h"

sfVector2f get_position(float x, float y)
{
    sfVector2f vector;
    vector.x = x;
    vector.y = y;
    return (vector);
}

int close_win(struct paint_t *paint, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        sfRenderWindow_close(paint->window);
    }
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(paint->window);
    }
}
