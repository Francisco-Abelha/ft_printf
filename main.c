/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgoncal2 <fgoncal2@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 22:25:16 by fgoncal2          #+#    #+#             */
/*   Updated: 2025/11/05 02:38:12 by fgoncal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("Test\n");
	ft_printf("Name: %s\n", "Bob");
	ft_printf("stats: %d\n", 42);
	ft_printf("crazy? i was %s once, they locked me in a %s\n", "crazy", "room");

	return (0);
}