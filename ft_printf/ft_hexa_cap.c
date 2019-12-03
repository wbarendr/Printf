/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexa_cap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 14:47:05 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/03 16:57:01 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

unsigned long long          check_type_hexa_cap(va_list * args, t_flags *flags)
{
    unsigned long long num;
    unsigned short int num2;
    unsigned char  num3;
    
    if (flags->h == 1)
    {
        num2 = va_arg(*args, unsigned int);
        return (num2);
    }
    if (flags->hh == 1)
    {
        num3 = va_arg(*args, unsigned int);
        return (num3);
    }
    if (flags->l == 1)
        num = va_arg(*args, unsigned long);
    else if (flags->ll == 1)
       num = va_arg(*args, unsigned long long);
    else
        num = va_arg(*args, unsigned int);
    return (num);
}

void            ft_hexa_cap(va_list *args, t_flags *flags, int *co)
{
    unsigned long long   num;
    unsigned long long   save_num;
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
    num = check_type_hexa_cap(args, flags);
     if (flags->space && num >= 0)
    {
        ft_putchar(' ');
        (*co)++;
    };
    save_num = num;
    while (save_num / 16)
    {
        save_num = save_num / 16;
        j++;
    }
    if (num >= 0 && flags->plus == 1)
        ft_putchar('+');
    if (num < 0)
        ft_putchar('-');
    print_hexa_cap(flags, num, j, co);
}

void            print_hexa_cap(t_flags *flags, unsigned long long num, int j, int *co)
{
    int i;
    int k;
    int p;

    p = 0;
    k = 0;
    i = 0;
    if (num < 0 || flags->plus == 1)
        i++;
    if (flags->hash == 1 && num > 0)
        i = i + 2;
    if (flags->hash == 1 && num > 0 && flags->zero == '0')
    {
        ft_putchar('0');
        ft_putchar('x');
    }
    if (flags->minus == 0)
        while (i < (flags->num - j) && i < (flags->num - flags->dotnum))
        {
            write(1, &flags->zero, 1);
            i++;
        }
    if (flags->hash == 1 && num > 0 && flags->zero == ' ')
    {
        ft_putchar('0');
        ft_putchar('x');
    }  
    while (k < flags->dotnum - j)
    {
        ft_putchar('0');
        k++;
    }
    if (!(flags->dotnum == 0 && flags->dot == 1 && num == 0))
    {
        ft_putnbr_base_cap(num, 1, &i);
    }
    if (flags->minus == 1)
        while (i < flags->num && p < (flags->num - flags->dotnum))
        {
            ft_putchar(' ');
            i++;
            p++;
        }
    (*co) = (*co) + i + k;
}