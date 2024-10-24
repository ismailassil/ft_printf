/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:46:01 by iassil            #+#    #+#             */
/*   Updated: 2023/11/25 13:33:01 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static size_t	ft_check_specifier(const char *str, va_list ptr, size_t *i)
{
	size_t	len;

	len = 0;
	if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		len += ft_putnbr(va_arg(ptr, int));
	else if (str[*i + 1] == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (str[*i + 1] == 'u')
		len += ft_uputnbr(va_arg(ptr, unsigned int));
	else if (str[*i + 1] == '%')
		len += ft_putchar('%');
	else if (str[*i + 1] == 'p')
		len += ft_hex_ptr(va_arg(ptr, void *));
	else if (str[*i + 1] == 'x')
		len += ft_hex(va_arg(ptr, int), 'x');
	else if (str[*i + 1] == 'X')
		len += ft_hex(va_arg(ptr, int), 'X');
	else if (str[*i + 1] == 'c')
		len += ft_putchar(va_arg(ptr, int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	size_t	len;
	size_t	i;

	va_start(ptr, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			else
				len += ft_check_specifier(str, ptr, &i);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (len);
}
