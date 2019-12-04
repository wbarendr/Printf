/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:11:55 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/04 19:56:35 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_fd(long long n, int fd, int *i)
{
	char c;

	if (n < 0)
		n = n * -1;
	if (n < 10)
	{
		c = n + 48;
		write(fd, &c, 1);
		(*i)++;
		return ;
	}
	ft_putnbr_fd((n / 10), fd, i);
	ft_putnbr_fd((n % 10), fd, i);
}

void	ft_putnbr_base(unsigned long long n, int fd, int *i)
{
	char			c;
	unsigned int	k;

	k = 10;
	if (n < 16)
	{
		if (n > 9)
		{
			while (k != n)
				k++;
			c = 'a' + (k - 10);
		}
		else
			c = n + 48;
		write(1, &c, 1);
		(*i)++;
		return ;
	}
	ft_putnbr_base((n / 16), fd, i);
	ft_putnbr_base((n % 16), fd, i);
}

void	ft_putnbr_base_cap(unsigned long long n, int fd, int *i)
{
	char			c;
	unsigned int	k;

	k = 10;
	if (n < 16)
	{
		if (n > 9)
		{
			while (k != n)
				k++;
			c = 'A' + (k - 10);
		}
		else
			c = n + 48;
		write(1, &c, 1);
		(*i)++;
		return ;
	}
	ft_putnbr_base_cap((n / 16), fd, i);
	ft_putnbr_base_cap((n % 16), fd, i);
}

void	ft_putnbr_unsigned(unsigned long long n, int fd, int *i)
{
	char c;

	if (n < 10)
	{
		c = n + 48;
		write(fd, &c, 1);
		(*i)++;
		return ;
	}
	ft_putnbr_fd((n / 10), fd, i);
	ft_putnbr_fd((n % 10), fd, i);
}
