# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 17:04:10 by lcombo            #+#    #+#              #
#    Updated: 2022/01/12 18:43:10 by lcombo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libftprintf.a

SRCS		=	ft_printf.c	ft_write.c
HEAD 		= 	ft_printf.h

OBJS 		= 	$(SRCS:%.c=%.o)
RM 			= 	rm -f

CC 			= 	gcc
CFLAGS 		= 	-Wall -Wextra -Werror -I$(HEAD)

.PHONY: 		all clean fclean re

all:			$(NAME)

$(NAME):		$(OBJS) $(HEAD)
				ar rcs $(NAME) $?

%.o	: %.c $(HEAD)
				$(CC) $(CFLAGS) -c $< -o $@

clean: 
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all
