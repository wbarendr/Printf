/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointer.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 18:36:29 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/04 19:48:04 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_pre(int *co, unsigned long long ptrint, t_flags *flags, int j)
{
	ft_putchar('0');
	ft_putchar('x');
	while (flags->dotnum > (j - 2))
	{
		ft_putchar('0');
		j++;
		(*co)++;
	}
	ft_putnbr_base(ptrint, 1, co);
	(*co) = (*co) + 2;
	if (flags->minus == 1)
		while (flags->num > j)
		{
			ft_putchar(' ');
			j++;
			(*co)++;
		}
}

void	print_null(int *co, t_flags *flags, int j)
{
	ft_putchar('0');
	ft_putchar('x');
	while (flags->dotnum > (j - 2))
	{
		ft_putchar('0');
		j++;
		(*co)++;
	}
	if (!(flags->dotnum == 0 && flags->dot == 1))
	{
		ft_putchar('0');
		(*co)++;
	}
	(*co) = (*co) + 2;
	if (flags->minus == 1)
		while (flags->num > 3)
		{
			ft_putchar(' ');
			flags->num--;
			(*co)++;
		}
}

void	ft_pointer(va_list *args, t_flags *flags, int *co)
{
	unsigned long long		ptrint;
	unsigned long long		save_ptrint;
	int						j;

	j = 3;
	ptrint = va_arg(*args, unsigned long long int);
	save_ptrint = ptrint;
	while (save_ptrint / 16)
	{
		save_ptrint = save_ptrint / 16;
		j++;
	}
	if (flags->minus == 0)
		while (flags->num > j)
		{
			ft_putchar(flags->zero);
			j++;
			(*co)++;
		}
	if (!ptrint)
	{
		print_null(co, flags, j);
		return ;
	}
	print_pre(co, ptrint, flags, j);
}
