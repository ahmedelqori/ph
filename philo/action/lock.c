/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:27:23 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/28 10:03:22 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int check_how_many_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->mutex_eat);
	if (philo->lock == 0)
	{
		if (philo->how_many_eat == data->inputs->nb_ph_me)
		{
			data->all_eat += 1;
			philo->lock = 1;
		}
		if (data->all_eat == data->inputs->number_of_philosophers)
		{
			pthread_mutex_lock(&data->mutex_eat);
			return (0);
		}
	}
	pthread_mutex_unlock(&data->mutex_eat);
	return (1);
}

int lock(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->mutex_dead);

	if (data->died == 1 || data->all_eat == data->inputs->number_of_philosophers)
	{
		pthread_mutex_unlock(&data->mutex_dead);
		return (0);
	}
	if ((gettime(data) - philo->last_meal) > data->inputs->time_to_die)
	{
		data->died = 1;
		print(data, philo, DEAD, BOLDRED);
		pthread_mutex_unlock(&data->mutex_dead);
		return (0);
	}
	if (!check_how_many_eat(data, philo))
	{
		pthread_mutex_unlock(&data->mutex_dead);
		return (0);
	}
	pthread_mutex_unlock(&data->mutex_dead);
	return (1);
}