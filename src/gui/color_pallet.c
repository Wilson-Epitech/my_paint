/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** color_pallet
*/

#include "../../include/my.h"

sfColor color_pallet(int nb)
{
    if (nb == 0)
        return sfWhite;
    if (nb == 1)
        return sfBlack;
    if (nb == 2)
        return sfRed;
    if (nb == 3)
        return sfGreen;
    if (nb == 4)
        return sfBlue;
    if (nb == 5)
        return sfYellow;
    return sfBlack;
}
