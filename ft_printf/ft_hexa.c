/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hexa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:01:58 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/04 20:19:36 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long	check_type_hexa(va_list *args, t_flags *flags)
{
	unsigned long			num;
	unsigned long long		num1;
	unsigned short			num2;
	short					num3;

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

void				eh(t_flags *flags, unsigned long long n, int *co, int i)
{
	int p;

	p = 0;
	if (!(flags->dotnum == 0 && flags->dot == 1 && n == 0))
		ft_putnbr_base(n, 1, &i);
	if (flags->minus == 1)
		while (i < flags->num && p < (flags->num - flags->dotnum))
		{
			ft_putchar(' ');
			i++;
			p++;
		}
	(*co) = (*co) + i;
}

void				ph(t_flags *flags, unsigned long long num, int j, int *co)
{
	int i;
	int k;
	int p;

	p = 0;
	k = 0;
	i = 0;
	if (flags->plus == 1)
		i++;
	if (flags->hash == 1 && num != 0)
		i = i + 2;
	if (flags->hash == 1 && flags->zero == '0' && num != 0)
		ft_putstr("0x");
	if (flags->minus == 0)
		no_minus(flags, &i, j, num);
	if (flags->hash == 1 && flags->zero == ' ' && num != 0)
		ft_putstr("0x");
	while (k < flags->dotnum - j)
	{
		ft_putchar('0');
		k++;
		i++;
	}
	eh(flags, num, co, i);
}

void				ft_hexa(va_list *args, t_flags *flags, int *co)
{
	unsigned long long		num;
	unsigned long long		save_num;
	int						j;

	j = 1;
	num = check_type_hexa(args, flags);
	if (flags->space && flags->plus == 0)
	{
		ft_putchar(' ');
		(*co)++;
		flags->num--;
	}
	save_num = num;
	while (save_num / 16)
	{
		save_num = save_num / 16;
		j++;
	}
	if (flags->plus == 1)
		ft_putchar('+');
	ph(flags, num, j, co);
}
