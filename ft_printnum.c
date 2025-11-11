/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:18:19 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/10 18:56:42 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	num_len(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_printnum(int num)
{
	int		len;
	char	*str;

	if (num < 0)
		len = num_len(-num) + 1;
	else
		len = num_len(num);
	str = ft_itoa(num);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
