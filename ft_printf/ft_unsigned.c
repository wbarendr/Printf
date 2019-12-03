/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unsigned.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 19:11:44 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/03 16:57:06 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long          check_type_unsigned(va_list * args, t_flags *flags)
{
    long long num;
    short num2;

    if (flags->h == 1)
    {
        num2 = va_arg(*args, unsigned int);
        return (num2);
    }
    if (flags->l == 1)
        num = va_arg(*args, unsigned long);
    else if (flags->ll == 1)
       num = va_arg(*args, unsigned long long);
    else
        num = va_arg(*args, unsigned int);
    return (num);
}

void            ft_unsigned(va_list *args, t_flags *flags, int *co)
{
    unsigned long long int		num;
    unsigned long long int		save_num;
    int					        j;

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
    num = check_type_unsigned(args, flags);
     if (flags->space && num >= 0)
    {
        ft_putchar(' ');
        (*co)++;
    }
    save_num = num;
    while (save_num / 10)
    {
        save_num = save_num / 10;
        j++;
    }
    if (flags->plus == 1 && flags->dot == 0 && flags->zero == '0')
        ft_putchar('+');
    print_unsigned(flags, num, j, co);
}

void            print_unsigned(t_flags *flags, unsigned long long num, int j, int *co)
{
    int i;
    int k;
    int p;

    p = 0;
    k = 0;
    i = 0;
    if (flags->plus == 1)
        i++;
    if (flags->minus == 0)
         while (i < (flags->num - j) && i < (flags->num - flags->dotnum))
        {
            write(1, &flags->zero, 1);
            i++;
        }
    if ((flags->dot == 1 || flags->zero == ' ') && flags->plus == 1) 
        ft_putchar('+');
    while (k < flags->dotnum - j)
    {
        ft_putchar('0');
        k++;
        i++;
    }
    if (!(flags->dotnum == 0 && flags->dot == 1 && num == 0))
        ft_putnbr_unsigned(num, 1, &i);
    if (flags->minus == 1)
        while (i < flags->num && p < (flags->num - flags->dotnum))
        {
            ft_putchar(' ');
            i++;
            p++;
        }
    (*co) = (*co) + i;
}