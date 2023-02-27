/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerri <ccerri@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:29:17 by ccerri            #+#    #+#             */
/*   Updated: 2023/02/17 16:38:01 by ccerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += ft_putchr(nb % 10 + 48);
	return (count);
}

int	ft_pn_base(unsigned int nb, int base, char *format)
{
	int	count;

	count = 0;
	if (nb >= (unsigned int)base)
		count += ft_pn_base(nb / base, base, format);
	count += ft_putchr(format[nb % base]);
	return (count);
}

int	ft_pt_base(unsigned long nb)
{
	int		count;
	char	*format;

	format = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count += ft_pt_base(nb / 16);
	count += ft_putchr(format[nb % 16]);
	return (count);
}
