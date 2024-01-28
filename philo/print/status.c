/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:41:42 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/27 21:44:09 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void print(t_data *data, t_philo *philo, char *msg, char *color)
{
	printf("%s%lld ms\t%d\t%s\n", color, gettime(data), philo->id, msg);
}