#include "printf.h"
#include <stdio.h>

void            print_pre_pointer(int *co, unsigned int ptrint)
{
    int i;

    i = 1;
    while (ptrint / 16)
    {
        ptrint = ptrint / 16;
        i++;
    }
    ft_putchar('0');
    ft_putchar('x');
    ft_putchar('1');
    while (i < 8)
    {
        ft_putchar('0');
        i++;
        (*co)++;
    }
    (*co) = (*co) + 3;
}

void			ft_pointer(va_list *args, t_flags *flags, int *co)
{
    unsigned int    ptrint;

   	if (flags->star == 1)
		flags->num = va_arg(*args, int);
    ptrint = va_arg(*args, unsigned int);
    if (flags->minus == 0)
	    while (flags->num > 11)
	    {
		    ft_putchar(flags->zero);
		    flags->num--;
		    (*co)++;
	    }
    print_pre_pointer(co, ptrint);
    ft_putnbr_base(ptrint, 1, co);
    if (flags->minus == 1)
        while (flags->num > 11)
        {
		    ft_putchar(' ');
		    flags->num--;
            (*co)++;
        }
}