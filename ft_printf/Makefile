# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wbarendr <wbarendr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/30 18:26:35 by wbarendr       #+#    #+#                 #
#    Updated: 2019/11/30 18:28:40 by wbarendr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_atoi ft_putnbr_fd printf printf_utils ft_digit ft_pointer \
		ft_print_x ft_unsigned

CFILES	= $(SRCS:%=%.c)
OFILES	= $(SRCS:%=%.o)

INCLUDES = libft.h

all:	$(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(CFILES) -c
	ar rc $(NAME) $(OFILES)

clean:
	rm -f $(OFILES) $(OBONUS)
	rm -f bonus

fclean:		clean
	rm -f $(NAME)

re:	fclean all
