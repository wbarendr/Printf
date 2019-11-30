/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 15:31:42 by wbarendr       #+#    #+#                */
/*   Updated: 2019/11/30 18:01:13 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "printf.h"
#include <locale.h>

void		found_type(const char **s, va_list *args, t_flags *flags, int *co)
{
	if ((*s)[0] == 'c')
        ft_char(args, flags, co);
    else if ((*s)[0] == 's')
        ft_string(args, flags, co);
    else if ((*s)[0] == 'd')
        ft_digit(args, flags, co);
    else if ((*s[0] == '%'))
        ft_percentage(args, flags, co);
  /*  else if ((*s)[0] == 'p')
        ft_p(args, flags);
    else if ((*s)[0] == 'i')
        ft_int(args, flags);
    else if ((*s)[0] == 'u')
        ft_unsigned_int(args, flags);
	else if ((*s)[0] == 'x')
        ft_x(args, flags);
    else if ((*s)[0] == 'X')
        ft_X(args, flags) */;
    //ft_bonus((*s)[0], args, flags);
    (*s)++; 
}

int         find_type(char c)
{
    if (c >= 'c' && c <= 'g')
        return (0);
    if (c == 'i' || c == 'u' || c == 's' || c == 'n')
        return (0);
    if (c == 'x' || c == 'p' || c == 'X' || c == '%') 
        return (0);
    return (1);
}

void			found_percentage(const char **s, va_list *args, t_flags *flags, int *co)
{
    while (find_type((*s)[0]))
	{
        if ((*s)[0] == '0')
            flags->zero = '0';
        else if ((*s)[0] == '-')
            flags->minus = 1;
        else if ((*s)[0] == ' ')
            flags->space = 1;
        else if ((*s)[0] == '+')
            flags->plus = 1;
        else if ((*s)[0] >= '0' && (*s)[0] <= '9')
        {
            flags->num = ft_atoi(*s);
            while ((*s)[1] >= '0' && (*s)[1] <= '9')
                (*s)++;
        } 
        else if (*s[0] == 'l' && *s[1] != 'l')
            flags->l = 1;
        else if (*s[0] == 'l' && *s[1] == 'l')
            flags->ll = 1;
        else if (*s[0] == 'h' && *s[1] != 'h')
            flags->h = 1;
        else if (*s[0] == 'h' && *s[1] == 'h')
            flags->hh = 1;
        else if (*s[0] == '#')
            flags->hash = 1;
        else if (*s[0] == '*') // check eerst wat er gebeurd bij flag->num
            flags->star = 1;
        else if (*s[0] == '.')
            flags->dot = 1;
        (*s)++;
    }
	found_type(s, args, flags, co);
}

int 		ft_printf(const char *s, ...)
{
    va_list     args;
    t_flags     flags;
    int         co;
    va_start(args, s);

    co = 0;
    flags = ft_flags();
    va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			found_percentage(&s, &args, &flags, &co);
		}
        flags = ft_flags();
		ft_putchar((char)s[0]);
        co++;
		s++;
	}
    va_end(args);
    return (co);
}

int				main(void)
{
    char l;
	char str[] = "I like turtles";
    int i;

    i = 5732;
    l = 'x';
    //setlocale(LC_ALL, "en_US");
    printf("%d\n", printf("char: %c\nstring: %.19s \n", l, str));
    printf("%d\n", ft_printf("char: %c\nstring: %.19s \n", l, str));

    //printf("---%0*c\n", 8, l);
    ft_printf("ft-%0*c\n", 8, l);


/* 	printf("   %-0*%  %-+5d\n", 2, 99);
	ft_printf("ft %-0*%  %-+5d\n", 2, 99);
	printf("   %  -0*%  %-+5d\n", 15, 99);
	ft_printf("ft %  -0*%  %-+5d\n", 15, 99);
	printf("   % *%  %-+5d\n", 2, 99);
	ft_printf("ft % *%  %-+5d\n", 2, 99);
	printf("   % +  %  %-+5d\n", 99);
    ft_printf("ft % +  %  %-+5d\n", 99);
    printf("   %-+5d\n", i);
    ft_printf("ft %-+5d\n", i);
    printf("   %-5d\n", i);
    ft_printf("ft %-5d\n", i);
    printf("   %-+5d\n", -57);
    ft_printf("ft %-+5d\n", -57);
    printf("   %-5d\n", -57);
    ft_printf("ft %-5d\n", -57);
    //ft_printf("%d\n", i);
    printf(":]%.2d\n", 3);
    ft_printf(":}%.2d\n", 3);
    printf(":]%     .*d\n", 8, -983);
    ft_printf(":}%     .*d\n", 8, -983);
    printf(" - %s\n", str);
    ft_printf("---%s\n", str);
    printf(" - %-25s\n", str);
    ft_printf("---%-25s\n", str);
    printf(" - %.40s\n", str);
    ft_printf("---%.40s\n", str) */;
    return (0);
}