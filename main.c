/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:25:16 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/07 16:58:58 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("Test\n");
	ft_printf("Name: %s\n", "Bob");
	ft_printf("stats: %d\n", 42);
	printf("printf says: %i\n", 0x19);
	printf("ft_printf says: %i\n", 0x19);
	ft_printf("crazy? i was %s once, they locked me in a %s\n", "crazy", "room");
	ft_printf("This is a char: %c\n", 'a');
	ft_printf("%%\n");
	
	return (0);
}
