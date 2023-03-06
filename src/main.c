/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** main
*/

#include "../include/my.h"

void mouse(struct paint_t *paint, struct button_s *boutton, sfEvent event)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(paint->window);
    paint->pos = sfRenderWindow_mapPixelToCoords(paint->window,pos_mouse, NULL);
    boutton->pos = paint->pos;
    sfVector2u size_win_base = sfRenderWindow_getSize(paint->window);
    sfVector2i tmp = vec_u_to_i(size_win_base.x, size_win_base.y);
    paint->size_win = sfRenderWindow_mapPixelToCoords(paint->window, tmp, NULL);
    if (paint->pos.x < paint->size_win.x
    && paint->pos.y < paint->size_win.y &&
    paint->pos.x > 0 && paint->pos.y > 100) {
        sfRenderWindow_setMouseCursorVisible(paint->window, sfFalse);
        paint->display_pixel == 0;
    } else {
        sfRenderWindow_setMouseCursorVisible(paint->window, sfTrue);
        paint->display_pixel == 1;
    }
}

void loop(struct paint_t *paint, struct button_s *boutton, sfEvent event)
{
    struct pen_t *pen = malloc(sizeof(struct pen_t));
    init_pen(paint, pen);
    while (sfRenderWindow_isOpen(paint->window)) {
        sfRenderWindow_clear(paint->window, sfWhite);
        sfRenderWindow_pollEvent(paint->window, &event);
        mouse(paint, boutton, event);
        close_win(paint, event);
        draw_all(paint, event, pen);
        for (int i = 0; i < 4; i++) {
            button(boutton, event, i);
        }
        sfRenderWindow_display(paint->window);
    }
}

int main(int argc, char **argv)
{
    struct paint_t *paint = malloc(sizeof(struct paint_t));
    struct button_s *boutton = malloc(sizeof(struct button_s));
    init_struct(paint, boutton);
    sfEvent event;
    loop(paint, boutton, event);
    fopen("./backup/backup.jpg", "w");
    sfImage_saveToFile(paint->image, "./backup/backup.jpg");
}
