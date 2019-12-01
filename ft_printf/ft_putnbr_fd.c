/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:11:55 by wbarendr       #+#    #+#                */
/*   Updated: 2019/11/30 20:32:24 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_fd(long long n, int fd, int *i)
{
	char c;

	//printf("nujm: %lld\n", n);
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
