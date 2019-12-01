/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unsigned.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 19:11:44 by wbarendr       #+#    #+#                */
/*   Updated: 2019/11/30 20:32:48 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void            ft_unsigned(va_list *args, t_flags *flags, int *co)
{
    unsigned int		num;
    unsigned int		save_num;
    int					j;

    j = 1;
    if (flags->star == 1)
        flags->num = va_arg(*args, int);
    if (flags->dot == 1)
        flags->zero = '0';
    num = va_arg(*args, int);
    if (flags->space)
        ft_putchar(' ');
    save_num = num;
    while (save_num / 10)
    {
        save_num = save_num / 10;
        j++;
    }
    print_digit(flags, num, j, co);
}

void            print_unsigned(t_flags *flags, unsigned int num, int j, int *co)
{
    int i;

    i = 0;
    if (flags->plus == 1)
        ft_putchar('+');
    if (flags->plus == 1)
        i++;
    if (flags->minus == 0)
        while (i < (flags->num - j))
        {
            write(1, &flags->zero, 1);
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