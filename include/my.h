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

#endif /* !paint_H_ */
