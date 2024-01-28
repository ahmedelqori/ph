/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:46:37 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/27 20:52:33 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void init_philos(t_data *data)
{
	int i;

	i = 0;
	while (i < data->inputs->number_of_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].time_to_die = data->inputs->time_to_die;
		data->philosophers[i].how_many_eat = 0;
		data->philosophers[i].last_meal = 0;
		data->philosophers[i].is_dead = 0;
		data->philosophers[i].fork = 0;
		data->philosophers[i].lock = 0;
		if (i < data->inputs->number_of_philosophers)
		{
			data->philosophers[i].left = i;
			data->philosophers[i].right = (i + 1) % data->inputs->number_of_philosophers;
		}
		i++;
	}
}