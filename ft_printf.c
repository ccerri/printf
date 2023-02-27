/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerri <ccerri@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:41:14 by ccerri            #+#    #+#             */
/*   Updated: 2023/02/17 16:43:01 by ccerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pt(unsigned long nb)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_pt_base(nb);
	return (count);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	check_type(char *s, int i, va_list args)
{
	if (s[i] == 'c')
		return (ft_putchr(va_arg(args, int)));
	else if (s[i] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s[i] == 'p')
		return (ft_print_pt(va_arg(args, unsigned long)));
	else if (s[i] == 'd' || s[i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (s[i] == 'u')
		return (ft_pn_base(va_arg(args, unsigned int), 10, "0123456789"));
	else if (s[i] == 'x')
		return (ft_pn_base(va_arg(args, unsigned int), 16, "0123456789abcdef"));
	else if (s[i] == 'X')
		return (ft_pn_base(va_arg(args, unsigned int), 16, "0123456789ABCDEF"));
	else if (s[i] == '%')
		return (write(1, &s[i], 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, s);
	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += check_type((char *)s, i + 1, args);
			i++;
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
