/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccerri <ccerri@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:42:00 by ccerri            #+#    #+#             */
/*   Updated: 2023/02/17 16:43:24 by ccerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchr(int c);
int	ft_putstr(char *s);
int	ft_printf(const char *s, ...);
int	check_type(char *s, int i, va_list args);
int	ft_strlen(char *s);
int	ft_pt_base(unsigned long nb);
int	ft_pn_base(unsigned int nb, int base, char *format);
int	ft_putnbr(int nb);

#endif