/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 14:39:13 by wbarendr       #+#    #+#                */
/*   Updated: 2019/11/30 22:41:59 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
    flags.dotnum = 0;
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
    if (flags->star == 1 && flags->dot == 1)
		flags->dotnum = va_arg(*args, int);
	if (flags->star == 1 && flags->dot == 0)
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
	if (flags->star == 1 && flags->dot == 1)
		flags->dotnum = va_arg(*args, int);
    if (flags->star == 1 && flags->dot == 0)
        flags->num = va_arg(*args, int);
	str = va_arg(*args, char*);
    while ((flags->num - ft_strlen(str)) > j && flags->minus == 0 && flags->dot == 0)
    {
        ft_putchar(' ');
        j++;
    }
	while (str[i] && !(i >= flags->dotnum && flags->dot == 1))
	{
		write(1, &str[i], 1);
		i++;
	}
    while (flags->dotnum > i + j && flags->dot == 0)
    {
        ft_putchar(' ');
        i++;
    }
	(*co) = (*co) + i + j;
}
