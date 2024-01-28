/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 09:21:07 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/28 10:17:33 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void sleeping(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->mutex_eat);
	if (data->died == 0 && data->all_eat != data->inputs->number_of_philosophers)
	{
		pthread_mutex_unlock(&data->mutex_eat);
		print(data, philo, SLEEP, BOLDMAGENTA);
		ft_usleep(data->inputs->time_to_sleep);
		return;
	}
	pthread_mutex_unlock(&data->mutex_eat);
}