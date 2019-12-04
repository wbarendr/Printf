/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 14:39:13 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/04 19:58:13 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_flags			ft_flags(void)
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
	flags.stardot = 0;
	return (flags);
}

int				find_type(char c)
{
	if ((c >= 'c' && c <= 'g') || c == '\0')
		return (0);
	if (c == 'i' || c == 'u' || c == 's' || c == 'n')
		return (0);
	if (c == 'x' || c == 'p' || c == 'X' || c == '%')
		return (0);
	return (1);
}

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
