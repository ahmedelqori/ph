/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:21:48 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/28 09:55:53 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void init_inputs(t_data *data, char **av)
{
	data->inputs->number_of_philosophers = ft_atoi(av[1]);
	data->inputs->time_to_die = ft_atoi(av[2]);
	data->inputs->time_to_eat = ft_atoi(av[3]);
	data->inputs->time_to_sleep = ft_atoi(av[4]);
	data->inputs->nb_ph_me = -1;
	if (av[5])
		data->inputs->nb_ph_me = ft_atoi(av[5]);
}

static void free_init_data(t_data *data)
{
	free(data->inputs);
	free(data->arr_forks);
	free(data->mutex_forks);
	free(data->philosophers);
	free(data);
}

int init_data(t_data *data, char **av)
{
	data->inputs = ft_calloc(1, sizeof(t_inputs), ALLOC_FAIL_INPUTS);
	if (data->inputs == NULL)
	{
		free(data);
		return (1);
	}
	init_inputs(data, av);
	if (init_alloc(data) == 1)
		return (1);
	if (init_mutex(data) == 1)
	{
		free_init_data(data);
		return (1);
	}
	init_philos(data);
	return (0);
}