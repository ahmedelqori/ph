/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:27:15 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/27 20:58:03 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int free_init_alloc(t_data *data, int n)
{
	if (n >= 1)
		free(data->arr_forks);
	if (n >= 2)
		free(data->mutex_forks);
	free(data->inputs);
	free(data);
	return (1);
}

int init_alloc(t_data *data)
{
	data->arr_forks = ft_calloc(data->inputs->number_of_philosophers, sizeof(int), ALLOC_FAIL_ARR_FORKS);
	if (data->arr_forks == NULL)
		return (free_init_alloc(data, 3));
	data->mutex_forks = ft_calloc(data->inputs->number_of_philosophers, sizeof(pthread_mutex_t), ALLOC_FAIL_MUTEX_FORKS);
	if (data->mutex_forks == NULL)
		return (free_init_alloc(data, 1));
	data->philosophers = ft_calloc(data->inputs->number_of_philosophers, sizeof(t_philo), ALLOC_FAIL_THREADS);
	if (data->philosophers == NULL)
		return (free_init_alloc(data, 2));
	return (0);
}