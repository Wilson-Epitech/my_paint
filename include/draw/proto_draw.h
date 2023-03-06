/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** proto_draw
*/

#ifndef PROTO_DRAW_H_
    #define PROTO_DRAW_H_

    #include "../include.h"
    #include "struct_draw.h"

int check_pixel(float y,float x, float size, struct paint_t *paint);
int paint_win(sfEvent event, struct paint_t *paint);
sfColor color_pallet(int nb, struct paint_t *paint, int n);
void color_select(struct paint_t *paint, sfEvent event);
void set_pen(struct paint_t *paint);
void set_eraser(struct paint_t *paint);
void pen_size(struct paint_t *paint, sfEvent event);
void square_cercle(struct paint_t *paint, sfVector2f pos, float size);
void draw_circle(struct paint_t *paint, int radius);
void pixel(struct paint_t *paint, sfVector2f pos, float size);
void hitbox_pixel(struct paint_t *paint, sfVector2f pos, float size);

#endif /* !PROTO_DRAW_H_ */
