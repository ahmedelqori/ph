/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:39:16 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/27 20:55:34 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

#include "../philo.h"

static int destroy_in_loop(t_data *data, int n)
{
	int i;

	i = 0;
	while (i < n)
		pthread_mutex_destroy(&data->mutex_forks[i++]);
	return (1);
}

static int init_mutex_2(t_data *data, int i)
{
	if (pthread_mutex_init(&data->mutex_eat, NULL) != 0)
	{
		printf(BOLDRED "\n%s\n", FAIL_MUTEX);
		pthread_mutex_destroy(&data->mutex_dead);
		return (destroy_in_loop(data, i));
	}
	if (pthread_mutex_init(&data->mutex_count, NULL) != 0)
	{
		printf(BOLDRED "\n%s\n", FAIL_MUTEX);
		pthread_mutex_destroy(&data->mutex_dead);
		pthread_mutex_destroy(&data->mutex_eat);
		return (destroy_in_loop(data, i));
	}
	if (pthread_mutex_init(&data->mutex_plus, NULL) != 0)
	{
		printf(BOLDRED "\n%s\n", FAIL_MUTEX);
		pthread_mutex_destroy(&data->mutex_dead);
		pthread_mutex_destroy(&data->mutex_eat);
		pthread_mutex_destroy(&data->mutex_count);
		return (destroy_in_loop(data, i));
	}
	return (0);
}

int init_mutex(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->inputs->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->mutex_forks[i], NULL) != 0)
		{
			printf(BOLDRED "\n%s\n", FAIL_MUTEX);
			return (destroy_in_loop(data, i));
		}
	}
	if (pthread_mutex_init(&data->mutex_dead, NULL) != 0)
	{
		printf(BOLDRED "\n%s\n", FAIL_MUTEX);
		return (destroy_in_loop(data, i));
	}
	return (init_mutex_2(data, i));
}