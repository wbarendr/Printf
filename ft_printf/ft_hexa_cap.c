#include "printf.h"

void            ft_hexa_cap(va_list *args, t_flags *flags, int *co)
{
    unsigned int         num;
    unsigned int         save_num;
    int                  j;

    j = 1;
   if (flags->star == 1)
    {
        flags->num = va_arg(*args, int);
        if (flags->num < 0)
        {
            flags->minus = 1;
            flags->num = flags->num * -1;
        }
    }
    if (flags->stardot == 1)
        flags->dotnum = va_arg(*args, int);
    num = va_arg(*args, int);
    if (flags->space && num >= 0)
        ft_putchar(' ');
    save_num = num;
    while (save_num / 16)
    {
        save_num = save_num / 16;
        j++;
    }
    if (num < 0)
        j--;
    if (num >= 0 && flags->plus == 1)
        ft_putchar('+');
    if (num < 0)
        ft_putchar('-');
    print_hexa_cap(flags, num, j, co);
}

void            print_hexa_cap(t_flags *flags, unsigned int num, int j, int *co)
{
    int i;
    int k;

    k = 0;
    i = 0;
    if (num < 0 || flags->plus == 1)
        i++;
    if (flags->minus == 0)
        while (i < (flags->num - j) && i < (flags->num - flags->dotnum))
        {
            write(1, &flags->zero, 1);
            i++;
        }
    while (k < flags->dotnum - j)
    {
        ft_putchar('0');
        k++;
    }
    if (flags->dotnum != 0 || flags->num != 0 || num != 0)
        ft_putnbr_base_cap(num, 1, &i);
    if (flags->minus == 1)
        while (i < flags->num)
        {
            ft_putchar(' ');
            i++;
        }
    (*co) = (*co) + i + k;
}