# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iassil <iassil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 16:10:10 by iassil            #+#    #+#              #
#    Updated: 2023/11/25 11:51:23 by iassil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile for PRINTF PROJECT

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRC_FILE =	ft_putstr.c		ft_putchar.c	ft_putnbr.c	\
			ft_uputnbr.c	ft_hex.c		ft_printf.c	\
			ft_hex_ptr.c

OBJECT_SRCF = ${SRC_FILE:.c=.o}
NAME = libftprintf.a
PRINTF_H = ft_printf.h

all: $(NAME)

%.o: %.c $(PRINTF_H)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECT_SRCF)
	$(AR) $@ $^

clean:
	$(RM) $(OBJECT_SRCF)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
