/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:24:36 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/23 01:06:44 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	take_forks(t_philos *philo)
{
	sem_wait(philo->s_data->sem_forks);
	printf("%llu philo %d  has taken a fork\n", (get_time() - \
	philo->s_data->time_start), philo->id + 1);
	sem_wait(philo->s_data->sem_forks);
	printf("%llu philo %d  has taken a fork\n", (get_time() - \
	philo->s_data->time_start), philo->id + 1);
	start_eating(philo);
}

void	start_eating(t_philos *philo)
{
	philo->last_time_eat = get_time();
	printf("%llu philo %d is eating\n", (get_time() - \
	philo->s_data->time_start), philo->id + 1);
	sleping_time(philo->s_data->time_to_eat);
	philo->nbr_to_eat++;
	sem_post(philo->s_data->sem_forks);
	sem_post(philo->s_data->sem_forks);
	star_sleeping(philo);
}

void	star_sleeping(t_philos *philo)
{
	printf("%llu philo %d is sleeping \n", (get_time() - \
	philo->s_data->time_start), philo->id + 1);
	sleping_time(philo->s_data->time_to_sleep);
	take_forks(philo);
}

void	star_thinking(t_philos *philo)
{
	printf("%llu philo %d is thinking \n", (get_time() - \
	philo->s_data->time_start), philo->id + 1);
	take_forks(philo);
}
