/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:17:56 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/27 20:18:12 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int ft_atoi(const char *str)
{
	long int i;
	long int j;

	i = 1;
	j = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		j = (*str - 48) + (j * 10);
		str++;
		if (i * j > 2147483647 || i * j < -2147483648)
			return (-1);
	}
	return (i * j);
}