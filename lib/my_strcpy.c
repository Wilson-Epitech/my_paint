/*
** MY_PAINT PROJECT, 2023
** my_paint
** File description:
** my_strcpy
*/

char *my_strcpy(char* dest, char* src)
{
    char *ptr = dest;
    while (*src != '\0') {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}
