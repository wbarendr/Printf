/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 14:14:06 by wbarendr       #+#    #+#                */
/*   Updated: 2019/11/30 20:34:13 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
 
typedef struct		s_flags
{
	int			space;
	int			minus;
	char		zero;
	int			plus;
	int			num;
	int			l;
	int			ll;
	int			h;
	int			hh;
	int			hash;
	int			dot;
	int			star;
	int 		dotnum;
}					t_flags;

t_flags				ft_flags(void);
void				ft_char(va_list *args, t_flags *flags, int *co);
void				ft_putchar(char c);
void				ft_string(va_list *args, t_flags *flags, int *co);
int					ft_atoi(const char *str);
void				ft_putnbr_fd(long long n, int fd, int *i);
void            	ft_digit(va_list *args, t_flags *flags, int *co);
void				ft_percentage(va_list *args, t_flags *flags, int *co);
void            	print_digit(t_flags *flags, long long num, int j, int *co);
void          		print_unsigned(t_flags *flags, unsigned int num, int j, int *co);
void				ft_unsigned(va_list *args, t_flags *flags, int *co);
void            	ft_hexa(va_list *args, t_flags *flags, int *co);
void				ft_putnbr_base(long long n, int fd, int *i);
void            	print_hexa(t_flags *flags, int num, int j, int *co);
void           		print_hexa_cap(t_flags *flags, int num, int j, int *co);
void            	ft_hexa_cap(va_list *args, t_flags *flags, int *co);
void				ft_putnbr_base_cap(long long n, int fd, int *i);
void				ft_pointer(va_list *args, t_flags *flags, int *co);
void         	  	print_pre_pointer(int *co, unsigned int ptrint);

#endif
