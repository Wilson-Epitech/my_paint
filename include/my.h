/*
** MY_PAINT PROJECT, 2022
** bspaint
** File description:
** paint
*/

#ifndef PAINT_H_
    #define PAINT_H_

    #include "include.h"
    #include "struct.h"

void init_struct(struct paint_t *paint, struct button_s *boutton);

sfVector2f get_position(float x, float y);
int close_win(struct paint_t *paint, sfEvent event);

int paint_win(sfEvent event, struct paint_t *paint);

void button(struct button_s *boutton,
    struct paint_t *paint, sfEvent event, int i);

void gui(struct paint_t *paint, sfEvent event);
sfColor color_pallet(int nb, struct paint_t *paint, int n);
void color_select(struct paint_t *paint, sfEvent event);
void set_pen(struct paint_t *paint);
void set_eraser(struct paint_t *paint);
sfVector2i vec_u_to_i(float x, float y);
void pen_size(struct paint_t *paint, sfEvent event);
void square_cercle(struct paint_t *paint, sfVector2f pos, float size);
void draw_circle(struct paint_t *paint, int radius);
int check_pixel(float y,float x, float size, struct paint_t *paint);
void pixel(struct paint_t *paint, sfVector2f pos, float size);
void hitbox_pixel(struct paint_t *paint, sfVector2f pos, float size);

#endif /* !paint_H_ */
