/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:40 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/28 09:27:20 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_data *data;

	if (check_args(ac, av))
		return (1);
	data = ft_calloc(1, sizeof(t_data), ALLOC_FAIL_DATA);
	if (data == NULL)
		return (1);
	if (init_data(data, av) == 1)
		return (1);
	actions(data);
	return (0);
}