/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:50 by ael-qori          #+#    #+#             */
/*   Updated: 2024/01/28 09:27:12 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

// ==================== LIBRARY ==================== //

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <pthread.h>

// ==================== COLORS ==================== //

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDWHITE "\033[1m\033[37m"

// ==================== STATE ==================== //

#define FORK "has taken a fork"
#define EAT "is eating"
#define SLEEP "is sleeping"
#define THINK "is thinking"
#define MEALS "All Philosophers have finished eating"
#define DEAD "is dead"

// ==================== ERROR MESSGAE ==================== //

#define ARG_1_ERROR ">> NUMBER OF PHILOSOPHERS AT LEAST 1 <<"
#define ARG_2_ERROR ">> TIME TO DIE FROM 0 TO INT_MAX PLEAS <<"
#define ARG_3_ERROR ">> TIME TO EAT FROM 0 TO INT_MAX PLEAS <<"
#define ARG_4_ERROR ">> TIME TO SLEEP FROM 0 TO INT_MAX PLEAS <<"
#define ARG_5_ERROR ">> NUMBER OF TIMES FROM 0 TO INT_MAX PLEAS <<"

#define ARG_ONLY_DIGIT ">> NEED ONLY DIGITS AND POSITIVE NUMBERS <<"
#define ARG_FORMAT ">> [NUMBER_OF_PHILOSOPHERS] [TIME_TO_DIE] \
 [TIME_TO_EAT] [TIME_TO_SLEEP] [NBOF_PHILOSOPHER_ME] <<"

#define ALLOC_FAIL_DATA ">> MALLOC FAIL IN DATA <<"
#define ALLOC_FAIL_INPUTS ">> MALLOC FAIL IN INPUTS <<"
#define ALLOC_FAIL_ARR_FORKS ">> MALLOC FAIL IN ARR_FORKS<<"
#define ALLOC_FAIL_MUTEX_FORKS ">> MALLOC FAIL IN MUTEX FORKS<<"
#define ALLOC_FAIL_THREADS ">> MALLOC FAIL IN PTHREAD<<"

#define FAIL_MUTEX ">> FAIL INIT MUTEX <<"

// ==================== STRUCTERS ==================== //

typedef struct timeval t_time;

typedef struct s_philo
{
	int id;
	int fork;
	int left;
	int right;
	int is_dead;
	int lock;
	long long last_meal;
	int time_to_die;
	int how_many_eat;
	pthread_t thread;
} t_philo;

typedef struct s_inputs
{
	int nb_ph_me;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_philosophers;
} t_inputs;

typedef struct s_data
{
	int died;
	int all_eat;
	long long time_zero;
	int *arr_forks;
	int can_i_print;
	pthread_mutex_t *mutex_forks;
	pthread_mutex_t mutex_eat;
	pthread_mutex_t mutex_plus;
	pthread_mutex_t mutex_dead;
	pthread_mutex_t mutex_count;
	t_inputs *inputs;
	t_philo *philosophers;
} t_data;

// ==================== PROTO_TYPE ==================== //

/*************** LIBFT ***************/

int ft_atoi(const char *str);
void *ft_calloc(size_t count, size_t size, char *msg);

/*************** PRINT ***************/

int print_return_n(char *msg, int n);
void *print_return_null(char *msg);
void print(t_data *data, t_philo *philo, char *msg, char *color);
/*************** CHECK_ARGS ***************/

int check_args(int ac, char **av);

/*************** INIT ***************/
int init_data(t_data *data, char **av);
int init_alloc(t_data *data);
int init_mutex(t_data *data);
void init_philos(t_data *data);

/*************** TIME  ***************/
void ft_usleep(long long time);
long long gettime(t_data *data);

/*************** action  ***************/
void actions(t_data *data);
int lock(t_data *data, t_philo *philo);
void philo_one(t_data *data, t_philo *philo);
void eating(t_data *data, t_philo *philo);
void sleeping(t_data *data, t_philo *philo);

#endif