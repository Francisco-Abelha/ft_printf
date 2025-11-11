/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:04:05 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/11 00:49:13 by fgoncal2         ###   ########.fr       */
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

static void	reverse(char str[], int length)
{
	int		start;
	int		end;
	char	temp;

	end = length - 1;
	start = 0;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}
char	*uitoa(unsigned int num, char* str, int base)
{
	int	i;
	int	rem;

	i = 0;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	str[i] = '\0';
	reverse(str, i);
	return (str);
}

int	ft_printunsigned(unsigned int num)
{
	int		len;
	char	*str;

	len = num_len(num);
	str = ft_calloc(len, sizeof(unsigned int));
	uitoa(num, str, 10);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
