/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 14:14:49 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/04 19:54:33 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_char(va_list *args, t_flags *flags, int *co)
{
	char c;

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

void			ft_percentage(t_flags *flags, int *co)
{
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
	char	*str;
	int		j;
	int		k;

	k = 0;
	str = va_arg(*args, char*);
	if (!str)
		str = "(null)";
	if (flags->dotnum < ft_strlen(str) && flags->dot == 1)
		j = flags->dotnum;
	else
		j = ft_strlen(str);
	while (flags->num > j && flags->minus == 0)
	{
		ft_putchar(flags->zero);
		j++;
		k++;
	}
	(*co) = (*co) + k;
	write_string(flags, str, j, co);
}

void			write_string(t_flags *flags, char *str, int j, int *co)
{
	int i;

	i = 0;
	while (str && str[i] && !(i >= flags->dotnum && flags->dot == 1))
	{
		write(1, &str[i], 1);
		i++;
	}
	while (flags->minus == 1 && flags->num > j)
	{
		ft_putchar(' ');
		i++;
		j++;
	}
	(*co) = (*co) + i;
}
