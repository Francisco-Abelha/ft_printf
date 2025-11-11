/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:37:34 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/11 00:59:53 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned	int num)
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

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}
static char	*citoa(unsigned int num, char* str, int base)
{
	int i;

	i = 0;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (num != 0)
	{
		int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }
    str[i] = '\0';
    reverse(str, i);
    return str;
}

int	ft_printhex(unsigned int num, const char format)
{
	int		len;
	char	*str;
	int		i;

	if (num == 0)
		return (write(1, "0", 1));
	len = num_len(num);
	str = ft_calloc(len, sizeof(int));
	citoa(num, str, 16);
	i = 0;
	while (str[i] != '\0')
	{
		if (format == 'x')
			str[i] = ft_tolower(str[i]);
		else
			str[i] = ft_toupper(str[i]);
		i++;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (ft_hex_len(num));
}
