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
sfColor color_pallet(int nb);

#endif /* !paint_H_ */
