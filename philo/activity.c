/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:24:36 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/18 04:08:27 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philos *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->s_data->forks[(philo->id + 1) % \
		philo->s_data->num_philos]);
		printf("%llu philo %d take fork\n", (get_time() - \
		philo->s_data->time_start), philo->id + 1);
		pthread_mutex_lock(&philo->s_data->forks[philo->id]);
		printf("%llu philo %d take fork\n", (get_time() - \
		philo->s_data->time_start), philo->id + 1);
	}
	else if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->s_data->forks[philo->id]);
		printf("%llu philo %d take fork\n", (get_time() - \
		philo->s_data->time_start), philo->id + 1);
		pthread_mutex_lock(&philo->s_data->forks[(philo->id + 1) % \
		philo->s_data->num_philos]);
		printf("%llu philo %d take fork\n", (get_time() - \
		philo->s_data->time_start), philo->id + 1);
	}
	start_eating(philo);
}

void	start_eating(t_philos *philo)
{
	philo->is_eat = 1;
	philo->last_time_eat = get_time();
	printf("%llu philo %d strat eating\n", (get_time() - \
	philo->s_data->time_start), philo->id + 1);
	sleping_time(philo->s_data->time_to_eat);
	philo->is_eat = 0;
	philo->nbr_to_eat++;
	pthread_mutex_unlock(&philo->s_data->forks[philo->id]);
	pthread_mutex_unlock(&philo->s_data->forks[(philo->id + 1) % \
	philo->s_data->num_philos]);
	star_sleeping(philo);
}

void	star_sleeping(t_philos *philo)
{
	printf("%llu philo %d is sleeping \n", (get_time() - \
	philo->s_data->time_start), philo->id + 1);
	sleping_time(philo->s_data->time_to_sleep);
	start_eating(philo);
}

void	star_thinking(t_philos *philo)
{
	printf("%llu philo %d is thinking \n", (get_time() - \
	philo->s_data->time_start), philo->id + 1);
	take_forks(philo);
}
