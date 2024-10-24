/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:37:10 by iassil            #+#    #+#             */
/*   Updated: 2023/11/19 14:19:23 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_converter(unsigned int nbr, char *base, int *count)
{
	if (nbr > 15)
	{
		ft_converter(nbr / 16, base, count);
		ft_converter(nbr % 16, base, count);
	}
	else if (nbr < 16)
		*count += ft_putchar(base[nbr]);
}

int	ft_hex(unsigned int nbr, char type)
{
	char			*upper_base;
	char			*lower_base;
	static int		len;

	len = 0;
	upper_base = "0123456789ABCDEF";
	lower_base = "0123456789abcdef";
	if (type == 'x')
		ft_converter(nbr, lower_base, &len);
	else if (type == 'X')
		ft_converter(nbr, upper_base, &len);
	return (len);
}
