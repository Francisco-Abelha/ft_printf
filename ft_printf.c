/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:19:28 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/07 16:59:48 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				ft_putstr_fd(va_arg(args, char *), 1);
				format++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				ft_putstr_fd(ft_itoa(va_arg(args, int)), 1);
				format++;
			}
			else if (*format == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				format++;
			}
			else if (*format == '%')
			{
				ft_putchar_fd('%', 1);
				format++;
			}
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
	}
	va_end(args);
	return (0);
}
