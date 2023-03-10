/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** proto_menu
*/

#ifndef PROTO_MENU_H_
    #define PROTO_MENU_H_

    #include "../include.h"
    #include "struct_menu.h"

void button(struct button_s *boutton, sfEvent event, int i);
void menu_redir(struct button_s *boutton, struct paint_t *paint);
void save_menu(sfImage *image);

#endif /* !PROTO_MENU_H_ */
