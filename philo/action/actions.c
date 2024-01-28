/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:16:06 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/28 10:24:32 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void magic(t_data *data, t_philo *philo)
{
	if (lock(data, philo))
		eating(data, philo);
	if (lock(data, philo))
		sleeping(data, philo);
	if (lock(data, philo))
		print(data, philo, THINK, BOLDBLUE);
}

void *philosophers(void *arg)
{
	static int i = 0;
	t_data *data;
	t_philo *philo;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->mutex_plus);
	philo = &data->philosophers[i++];
	pthread_mutex_unlock(&data->mutex_plus);
	if (philo->id % 2 == 0)
		ft_usleep(15);
	while (lock(data, philo))
	{
		if (data->inputs->number_of_philosophers == 1)
			philo_one(data, philo);
		else
			magic(data, philo);
	}
	return (NULL);
}

void actions(t_data *data)
{
	t_time time;
	int i;

	i = 0;
	gettimeofday(&time, NULL);
	data->time_zero = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (data->inputs->nb_ph_me == 0)
		return;
	while (i < data->inputs->number_of_philosophers)
	{
		data->philosophers[i].last_meal = data->time_zero;
		pthread_create(&data->philosophers[i].thread, NULL, &philosophers, data);
		i++;
	}
	i = -1;
	while (++i < data->inputs->number_of_philosophers)
		pthread_join(data->philosophers[i].thread, NULL);
}