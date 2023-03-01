/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** main
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    struct paint_t *paint = malloc(sizeof(struct paint_t));
    struct button_s *boutton = malloc(sizeof(struct button_s));
    init_struct(paint, boutton);
    sfEvent event;
    while (sfRenderWindow_isOpen(paint->window)) {
        sfRenderWindow_clear(paint->window, sfWhite);
        paint_win(event, paint);
        sfRenderWindow_pollEvent(paint->window, &event);
        close_win(paint, event);
        gui(paint, event);
        for (int i = 0; i < 4; i++) {
            button(boutton, paint, event, i);
        }
        sfRenderWindow_display(paint->window);
    }
}
