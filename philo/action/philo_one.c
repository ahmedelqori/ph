/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:52:48 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/28 09:30:27 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void philo_one(t_data *data, t_philo *philo)
{
	print(data, philo, FORK, BOLDYELLOW);
	ft_usleep(data->inputs->time_to_die);
	print(data, philo, DEAD, BOLDRED);
	pthread_mutex_lock(&data->mutex_dead);
	data->died = 1;
	pthread_mutex_unlock(&data->mutex_dead);
}