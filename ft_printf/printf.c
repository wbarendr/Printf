/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wbarendr <wbarendr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 15:31:42 by wbarendr       #+#    #+#                */
/*   Updated: 2019/12/03 17:06:34 by wbarendr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
//#include <locale.h>  

void		found_type(const char **s, va_list *args, t_flags *flags, int *co)
{
    if (flags->dot == 1)
        flags->zero = ' ';
	if ((*s)[0] == 'c')
        ft_char(args, flags, co);
    else if ((*s)[0] == 's')
        ft_string(args, flags, co);
    else if ((*s)[0] == 'd')
        ft_digit(args, flags, co);
    else if ((*s[0] == '%'))
        ft_percentage(args, flags, co);
    else if ((*s)[0] == 'i')
        ft_digit(args, flags, co);
    else if ((*s)[0] == 'u')
        ft_unsigned(args, flags, co);
	else if ((*s)[0] == 'x')
        ft_hexa(args, flags, co);
    else if ((*s)[0] == 'X')
        ft_hexa_cap(args, flags, co);
    else if ((*s)[0] == 'p')
        ft_pointer(args, flags, co);
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

void            find_flags(const char **s, t_flags *flags)
{
	if ((*s)[0] == '0')
        flags->zero = '0';
    else if ((*s)[0] == '-')
        flags->minus = 1;
    else if ((*s)[0] == ' ')
        flags->space = 1;
    else if ((*s)[0] == '+')
        flags->plus = 1;
    if ((*s)[0] == 'l' && (*s)[1] != 'l')
        flags->l = 1;
    if ((*s)[0] == 'l' && (*s)[1] == 'l')
        flags->ll = 1;
    else if ((*s)[0] == 'h' && (*s)[1] != 'h')
        flags->h = 1;
    else if ((*s)[0] == 'h' && (*s)[1] == 'h')
		flags->hh = 1;
	if (((*s)[0] == 'h' && (*s)[1] == 'h') || ((*s)[0] == 'l' && (*s)[1] == 'l'))
		(*s)++;
    if ((*s)[0] == '*')
        flags->star = 1;
	else if ((*s)[0] == '#')
        flags->hash = 1;
}

void			found_percentage(const char **s, va_list *args, t_flags *flags, int *co)
{
    while (find_type((*s)[0]))
	{
        find_flags(s, flags);
        if ((*s)[0] >= '0' && (*s)[0] <= '9')
        {
            flags->num = ft_atoi(*s);
            while ((*s)[1] >= '0' && (*s)[1] <= '9')
                (*s)++;
        }
        else if (*s[0] == '.')
		{
            flags->dot = 1;
            if ((*s)[1] == '*' || ((*s)[1] >= '0' && (*s)[1] <= '9')) 
			    (*s)++;
            if ((*s)[0] == '*')
                flags->stardot = 1;
			else if ((*s)[0] >= '0' && (*s)[0] <= '9')
				flags->dotnum = ft_atoi(*s);
            while ((*s)[1] >= '0' && (*s)[1] <= '9')
                (*s)++;
		}
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
        else 
        {
		    ft_putchar((char)s[0]);
            co++;
		    s++;
        }
        flags = ft_flags();
	}
    va_end(args);
    return (co);
}

/* int				main(void)
{
    ft_printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
    printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
    
    ft_printf("st118 %*d\n", 17, 0);
    printf("st118 %*d\n", 17, 0);
    ft_printf("%*d        %*i\n", 1, 0, 10, 10);
    printf("%*d        %*i\n", 1, 0, 10, 10);
    ft_printf("neg7 %*.*d\n", -25, 15, 0);
    printf("neg7 %*.*d\n", -25, 15, 0);
 
    ft_printf("%x\n", 0);
    printf("%x\n", 0);
    ft_printf("%01hhX !!\n", (unsigned char)0);
    printf("%01hhX !!\n", (unsigned char)0);
    
    ft_printf("%#0012x\n", 0xe);
    printf("%#0012x\n", 0xe);
    ft_printf("%#10.0x %0#x\n", 12345, 0); 
    printf("%#10.0x %0ls#x\n", 12345, 0); 
    ft_printf("%0#10.0X\n", 16);
    printf("%0#10.0X\n", 16);

    ft_printf("%---10.0xet\n", 0xaabb);
    printf("%---10.0xet\n", 0xaabb);
     printf("----\n");
    printf("----\n");
    printf("----\n");

    ft_printf("toto %0#0.4X    %#4.2xet c'est fini \n", 0x037a, 0x9e);
    printf("toto %0#0.4X    %#4.2xet c'est fini \n", 0x037a, 0x9e);

    printf("%d\n", printf("t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1));
    printf("%d\n", ft_printf("t %#7.5X%0006.2x et %lX!\n", 0xab, 0x876, 0xff11ff11ff1));
    printf("%d\n", printf("toto %0##0.4X%#4.2xet c'est fini \n", 0x037a, 0x9e));
    printf("%d\n", ft_printf("toto %0##0.4X%#4.2xet c'est fini \n", 0x037a, 0x9e));
    printf("%d\n", printf("cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0));
    printf("%d\n", ft_printf("cc%#.4X et %#0012x %#04hX !!\n", 0xaef, 0xe, (unsigned short)0));

    ft_printf("%#10x\n", 0x78aa);
    printf("%#10x\n", 0x78aa);
    
    printf("%d\n", ft_printf("%-3u\n", 194));
    printf("%d\n", printf("%-3u\n", 194));

    ft_printf("%llu\n", (unsigned long long)345612220);
    printf("%llu\n", (unsigned long long)345612220);
}  */