/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 14:39:13 by wbarendr       #+#    #+#                */
/*   Updated: 2019/11/30 18:05:00 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

t_flags         ft_flags(void)
{
    t_flags flags;

    flags.space = 0; 
    flags.minus = 0; 
    flags.zero = ' '; 
    flags.plus = 0; 
    flags.num = 0; 
    flags.l = 0; 
    flags.ll = 0; 
    flags.h = 0; 
    flags.hh = 0;
    flags.dot = 0;
    flags.star = 0;
    flags.hash = 0;
    return (flags); 
}

int             ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void            ft_putchar(char c)
{
    write(1, &c, 1);
}

void			ft_char(va_list *args, t_flags *flags, int *co)
{
    char c;

	if (flags->star == 1)
		flags->num = va_arg(*args, int);
    c = va_arg(*args, int);
    if (flags->minus == 0)
	    while (flags->num > 1)
	    {
		    ft_putchar(flags->zero);
		    flags->num--;
		    (*co)++;
	    }
    ft_putchar(c);
    (*co)++;
    if (flags->minus == 1)
        while (flags->num > 1)
        {
		    ft_putchar(' ');
		    flags->num--;
            (*co)++;
        }
}

void			ft_percentage(va_list *args, t_flags *flags, int *co)
{
	if (flags->star == 1)
		flags->num = va_arg(*args, int);
    if (flags->minus == 0)
	    while (flags->num > 1)
	    {
		    ft_putchar(flags->zero);
		    flags->num--;
		    (*co)++;
	    }
    ft_putchar('%');
    (*co)++;
    if (flags->minus == 1)
        while (flags->num > 1)
        {
		    ft_putchar(' ');
		    flags->num--;
            (*co)++;
        }
}

void			ft_string(va_list *args, t_flags *flags, int *co)
{
	char    *str;
	int     i;
    int     j;

    j = 0;
	i = 0;
	if (flags->star == 1)
		flags->num = va_arg(*args, int);
	str = va_arg(*args, char*);
    while ((flags->num - ft_strlen(str)) > j && flags->minus == 0 && flags->dot == 0)
    {
        ft_putchar(' ');
        j++;
    }
	while (str[i])
	{
		if (flags->dot == 1 && i >= flags->num)
			break ;
		write(1, &str[i], 1);
		i++;
	}
    while (flags->num > i + j && flags->dot == 0)
    {
        ft_putchar(' ');
        i++;
    }
	(*co) = (*co) + i + j;
}

void            ft_digit(va_list *args, t_flags *flags, int *co)
{
    char *str;
    long long num;
    long long save_num;
    int i;
    int j;

    i = 0;
    j = 1;
    if (flags->star == 1)
        flags->num = va_arg(*args, int);
    if (flags->dot == 1)
        flags->zero = '0';
    num = va_arg(*args, int);
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
    if (num < 0 || flags->plus == 1)
        i++;
    
    if (flags->minus == 1)
    {
        ft_putnbr_fd(num, 1, &i);
        while (i < flags->num)
        {
            ft_putchar(' ');
            i++;
        }
    }
    else
    {
        while (i < (flags->num - j))
        {
            write(1, &flags->zero, 1);
            i++;
        }
        ft_putnbr_fd(num, 1, &i);
    }
    (*co) = (*co) + i + j;
}
