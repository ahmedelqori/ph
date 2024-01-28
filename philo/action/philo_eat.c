/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:57:51 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/28 09:44:52 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void hold_fork(t_data *data, t_philo *philo, int pos)
{
	pthread_mutex_lock(&data->mutex_forks[pos]);
	if (data->arr_forks[pos] == 0)
	{
		data->arr_forks[pos] = 1;
		philo->fork += 1;
		if (lock(data, philo))
			print(data, philo, FORK, BOLDYELLOW);
	}
	pthread_mutex_unlock(&data->mutex_forks[pos]);
}

void eating(t_data *data, t_philo *philo)
{
	while (philo->fork != 2 && lock(data, philo))
	{
		hold_fork(data, philo, philo->left);
		hold_fork(data, philo, philo->right);
	}
	if (lock(data, philo))
	{
		philo->last_meal = gettime(data);
		if (lock(data, philo))
			print(data, philo, EAT, BOLDGREEN);
		philo->how_many_eat += 1;
		lock(data, philo);
		ft_usleep(data->inputs->time_to_eat);
		pthread_mutex_lock(&data->mutex_forks[philo->left]);
		data->arr_forks[philo->left] = 0;
		pthread_mutex_unlock(&data->mutex_forks[philo->left]);
		pthread_mutex_lock(&data->mutex_forks[philo->right]);
		data->arr_forks[philo->right] = 0;
		pthread_mutex_unlock(&data->mutex_forks[philo->right]);
		philo->fork = 0;
		lock(data, philo);
	}
}