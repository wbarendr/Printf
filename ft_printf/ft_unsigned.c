/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unsigned.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 19:11:44 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/04 20:28:57 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long	check_type_unsigned(va_list *args, t_flags *flags)
{
	unsigned long		num;
	unsigned long long	num1;
	unsigned short		num2;
	short				num3;

	if (flags->hh == 1)
	{
		num3 = va_arg(*args, unsigned int);
		return (num3);
	}
	if (flags->h == 1)
	{
		num2 = va_arg(*args, unsigned int);
		return (num2);
	}
	if (flags->l == 1)
	{
		num = va_arg(*args, unsigned long);
		return (num);
	}
	else if (flags->ll == 1)
		num1 = va_arg(*args, unsigned long long);
	else
		num1 = va_arg(*args, unsigned int);
	return (num1);
}

void				p_u(t_flags *flags, unsigned long long num, int j, int *co)
{
	int i;
	int p;

	p = 0;
	i = 0;
	if (flags->plus == 1)
		i++;
	if (flags->minus == 0)
		no_minus(flags, &i, j, num);
	if ((flags->dot == 1 || flags->zero == ' ') && flags->plus == 1)
		ft_putchar('+');
	ft_precision(flags, j, &i);
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

void				ft_unsigned(va_list *args, t_flags *flags, int *co)
{
	unsigned long long int		num;
	unsigned long long int		save_num;
	int							j;

	j = 1;
	num = check_type_unsigned(args, flags);
	if (flags->space && flags->plus == 0)
	{
		ft_putchar(' ');
		(*co)++;
		flags->num--;
	}
	save_num = num;
	while (save_num / 10)
	{
		save_num = save_num / 10;
		j++;
	}
	if (flags->plus == 1 && flags->dot == 0 && flags->zero == '0')
		ft_putchar('+');
	p_u(flags, num, j, co);
}
