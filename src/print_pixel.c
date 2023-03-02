/*
** MY_PAINT PROJECT, 2023
** test
** File description:
** print_pixel
*/

#include "../include/my.h"

void hitbox_pixel(sfVector2f pos, struct paint_t *paint, float size)
{
    sfColor border = paint->color_pick;
    if (paint->gomme == 0) {
        sfSprite_setPosition(paint->pen,
        get_position(pos.x - (8 - size / 2), pos.y - (40 + size / 2)));
        sfRenderWindow_drawSprite(paint->window, paint->pen, 0);
    }
    if (paint->gomme == 1) {
        sfSprite_setPosition(paint->eraser,
        get_position(pos.x, pos.y - 45));
        sfRenderWindow_drawSprite(paint->window, paint->eraser, 0);
        border = sfBlack;
    }
    sfRectangleShape *pixel = sfRectangleShape_create();
    sfRectangleShape_setSize(pixel, get_position(size, size));
    sfRectangleShape_setFillColor(pixel, paint->color_pick);
    sfRectangleShape_setPosition(pixel,
    get_position(pos.x - size / 2, pos.y - size / 2));
    sfRectangleShape_setOutlineThickness(pixel,1);
    sfRectangleShape_setOutlineColor(pixel, border);
    sfRenderWindow_drawRectangleShape(paint->window, pixel, 0);
}

int check_pixel(float y,float x, float size, struct paint_t *paint)
{
    if (y - size <= 0 || y + size >= paint->size_win.y)
        return 0;
    if (x - size <= 0 || x + size >= paint->size_win.x)
        return 0;
    return 1;
}

void pixel(sfEvent event, struct paint_t *paint, sfVector2f pos, float size)
{
    int x = pos.x;
    int y = pos.y;
    size /= 2;
    y -= size;
    while (y < pos.y + size) {
        for (x = pos.x - size; x < pos.x + size &&
        check_pixel(pos.y, pos.x, size, paint); x++) {
            sfImage_setPixel(paint->image, x, y, paint->color_pick);
        }
        y++;
    }
}

int paint_win(sfEvent event, struct paint_t *paint)
{
    sfVector2f pos = paint->pos;
    sfVector2f size_win = paint->size_win;
    float size = paint->size_pen;
    if (paint->gomme == 1)
        size = 10;
    if (sfMouse_isButtonPressed(0) && pos.x < size_win.x
    && pos.y < size_win.y && pos.x > 0 && pos.y > 100) {
        pixel(event, paint, pos, size);
    }
    sfTexture *board_tex = sfTexture_createFromImage(paint->image, NULL);
    sfSprite *board = sfSprite_create();
    sfSprite_setTexture(board, board_tex, 0);
    sfRenderWindow_drawSprite(paint->window, board, NULL);
    sfTexture_destroy(board_tex);
    sfSprite_destroy(board);
    if (pos.x < size_win.x
    && pos.y < size_win.y && pos.x > 0 && pos.y > 100)
        hitbox_pixel(pos, paint, size);
}
