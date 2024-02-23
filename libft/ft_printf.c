/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:44:11 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/02 16:53:59 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dec(long int nbr, char *base)
{
	if (nbr < 0)
		return (write(1, "-", 1) + ft_dec(nbr * (-1), base));
	if (nbr > 9)
		return (ft_dec(nbr / 10, base) + write(1, &base[nbr % 10], 1));
	return (write(1, &base[nbr % 10], 1));
}

static int	ft_hex(unsigned long nbr, char *base)
{
	if (nbr > 15)
		return (ft_hex(nbr / 16, base) + write(1, &base[nbr % 16], 1));
	return (write(1, &base[nbr % 16], 1));
}

static int	ft_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_str("(null)"));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

static int	ft_conversor(char c, va_list va)
{
	if (c == 'c')
		return (write(1, &(char){va_arg(va, int)}, 1));
	if (c == 's')
		return (ft_str(va_arg(va, char *)));
	if (c == 'p')
		return (write(1, "0x", 2) + ft_hex(va_arg(va, unsigned long), HEX1));
	if (c == 'd' || c == 'i')
		return (ft_dec(va_arg(va, int), NUM));
	if (c == 'u')
		return (ft_dec(va_arg(va, unsigned int), NUM));
	if (c == 'x')
		return (ft_hex(va_arg(va, unsigned int), HEX1));
	if (c == 'X')
		return (ft_hex(va_arg(va, unsigned int), HEX2));
	return (write(1, &c, 1));
}

int	ft_printf(char const *s, ...)
{
	int		n;
	va_list	va;

	n = 0;
	va_start(va, s);
	while (*s)
	{
		if (*s == '%')
			n += ft_conversor(*++s, va);
		else
			n += write(1, s, 1);
		if (*s)
			s ++;
	}
	va_end(va);
	return (n);
}
