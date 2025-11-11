/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:55:35 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/10 21:24:02 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_printptr(unsigned long long num)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (num == 0)
		len += write(1, "0", 1);
	else
		len += ft_ptr_len(num);
	return (len);
}
