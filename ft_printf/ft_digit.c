/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 19:09:31 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/04 20:11:09 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long	check_type(va_list *args, t_flags *flags)
{
	long long	num;
	long		num1;
	short		num2;
	char		num3;

	if (flags->hh == 1)
	{
		num3 = va_arg(*args, int);
		return (num3);
	}
	if (flags->h == 1)
	{
		num2 = va_arg(*args, int);
		return (num2);
	}
	if (flags->l == 1)
	{
		num1 = va_arg(*args, long);
		return (num1);
	}
	else if (flags->ll == 1)
		num = va_arg(*args, long long);
	else
		num = va_arg(*args, int);
	return (num);
}

void		print_sign(long long num, t_flags *flags)
{
	if (num >= 0 && flags->plus == 1)
		ft_putchar('+');
	if (num < 0)
		ft_putchar('-');
}

void		ft_digit(va_list *args, t_flags *flags, int *co)
{
	long long		num;
	long long		save_num;
	int				j;

	j = 1;
	num = check_type(args, flags);
	if (flags->space && num >= 0 && flags->plus == 0)
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
	if (flags->dot == 0 && flags->zero == '0')
		print_sign(num, flags);
	print_digit(flags, num, j, co);
}

void		ft_precision(t_flags *flags, int j, int *i)
{
	while (0 < flags->dotnum - j)
	{
		ft_putchar('0');
		j++;
		(*i)++;
	}
}

void		print_digit(t_flags *flags, long long num, int j, int *co)
{
	int i;
	int p;

	p = 0;
	i = 0;
	if (num < 0 || flags->plus == 1)
		i++;
	if (flags->minus == 0)
		no_minus(flags, &i, j, num);
	if (flags->dot == 1 || flags->zero == ' ')
		print_sign(num, flags);
	ft_precision(flags, j, &i);
	if (!(flags->dotnum == 0 && flags->dot == 1 && num == 0))
		ft_putnbr_fd(num, 1, &i);
	if (flags->minus == 1)
		while (i < flags->num && p < (flags->num - flags->dotnum))
		{
			ft_putchar(' ');
			i++;
			p++;
		}
	(*co) = (*co) + i;
}
