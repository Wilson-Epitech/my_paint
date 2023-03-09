/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** converte
*/

#include "../include/my.h"

sfVector2f get_position(float x, float y)
{
    sfVector2f vector;
    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2i vec_u_to_i(float x, float y)
{
    sfVector2i vector;
    vector.x = x;
    vector.y = y;
    return (vector);
}
