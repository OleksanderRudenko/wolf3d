#include "libft.h"

char    *ft_itoa_base(int value, int base)
{
    char    *s;
    char    *hex;
    int     i;
    int     n;
 
    hex = "0123456789ABCDEF";
    n = value;
    i = 1;
    while (n /= base)
        i++;
    if (value < 0 && base == 10)
        i++;
    s = (char*)malloc(sizeof(char) * (i + 1));
    if (value < 0 && base == 10)
        s[0] = '-';
    if (value == 0)
        s[0] = 48;
    s[i] = '\0';
    while (value)
    {
        s[--i] = hex[value < 0 ? -(value % base) : value % base];
        value /= base;
    }
    return (s);
}