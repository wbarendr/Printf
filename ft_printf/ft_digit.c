/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 19:09:31 by wbarendr       #+#    #+#                */
/*   Updated: 2019/11/30 21:27:19 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

long long          check_type(va_list * args, t_flags *flags)
{
    long long num;
    short num2;

    if (flags->h == 1)
    {
        num2 = va_arg(*args, int);
        return (num2);
    }
    if (flags->l == 1)
        num = va_arg(*args, long);
    else if (flags->ll == 1)
       num = va_arg(*args, long long);
    else
        num = va_arg(*args, int);
    return (num);
}

void            ft_digit(va_list *args, t_flags *flags, int *co)
{
    long long     num;
    long long     save_num;
    int           j;

    j = 1;
    if (flags->star == 1)
        flags->dotnum = va_arg(*args, int);
    num = check_type(args, flags);
    if (flags->space && num >= 0)
        ft_putchar(' ');
    save_num = num;
    while (save_num / 10)
    {
        save_num = save_num / 10;
        j++;
    }
    if (num < 0)
        j--;
    if (num >= 0 && flags->plus == 1)
        ft_putchar('+');
    if (num < 0)
        ft_putchar('-');
    print_digit(flags, num, j, co);
}

void            print_digit(t_flags *flags, long long num, int j, int *co)
{
    int i;

    i = 0;
    if (num < 0 || flags->plus == 1)
        i++;
    if (flags->minus == 0)
        while (i < (flags->num - j))
        {
            write(1, &flags->zero, 1);
            i++;
        }
    while (i < flags->dotnum - j)
    {
        ft_putchar('0');
        i++;
    }
    ft_putnbr_fd(num, 1, &i);
    if (flags->minus == 1)
        while (i < flags->num)
        {
            ft_putchar(' ');
            i++;
        }
    (*co) = (*co) + i + j;
}
