/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** color_pallet
*/

#include "../../include/my.h"

sfColor color_pallet_pt2(int nb, struct paint_t *paint, int n)
{
    sfColor yanis = sfColor_fromRGB(185,138,131);
    if (nb == 6)
        return yanis;
    return sfBlack;
}

sfColor color_pallet(int nb, struct paint_t *paint, int n)
{
    if (nb == 0) {
        if (n == 0)
            paint->gomme = 1;
        return sfWhite;
    }
    if (n == 0)
        paint->gomme = 0;
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
    return color_pallet_pt2(nb, paint, n);
}
