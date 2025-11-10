/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:19:28 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/10 02:58:29 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	f_specifiers(va_list *args, const char format)
{
	int	chars_printed;

	chars_printed = 0;
	if (format == 'c')
		chars_printed += ft_printchar(va_arg(*args, int));
	else if (format == 's')
		chars_printed += ft_printstr(va_arg(*args, char *));
	else if (format == '%')
		chars_printed += ft_printchar('%');
	return (chars_printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars_printed;

	chars_printed = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				chars_printed += f_specifiers(&args, *format);
		}
		else
			chars_printed += ft_printchar(*format);
		format++;
	}
	va_end(args);
	return (chars_printed);
}
