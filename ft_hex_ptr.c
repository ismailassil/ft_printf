/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:12:15 by iassil            #+#    #+#             */
/*   Updated: 2023/11/19 14:21:26 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_ptr(unsigned long ptr, char *base, int *count)
{
	if (ptr > 15)
	{
		ft_convert_ptr(ptr / 16, base, count);
		ft_convert_ptr(ptr % 16, base, count);
	}
	else if (ptr < 16)
		*count += ft_putchar(base[ptr]);
}

int	ft_hex_ptr(void *str)
{
	int				len;
	unsigned long	ptr;
	char			*base;

	len = 0;
	ptr = (unsigned long)str;
	base = "0123456789abcdef";
	len += ft_putstr("0x");
	ft_convert_ptr(ptr, base, &len);
	return (len);
}
