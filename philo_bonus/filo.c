/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:40:41 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/23 01:08:31 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_is_dead(void *check)
{
	t_philos	*philo;
	int			i;

	philo = (t_philos *)check;
	while (1)
	{
		i = get_time() - philo->last_time_eat;
		if (i > philo->s_data->time_to_die)
		{
			sem_wait(philo->s_data->sem_check);
			printf("%llu philo %d died\n", (get_time() - \
			philo->s_data->time_start), philo->id + 1);
			break ;
		}
		if (check_final_eating(philo))
			break ;
	}
	sem_post(philo->s_data->barage);
	return (NULL);
}

void	*check(void *address)
{
	t_philos	*philo;

	philo = (t_philos *)address;
	sem_wait(philo->s_data->barage);
	sem_post(philo->s_data->barage);
	exit(0);
}

void	ft_philo(t_philos *philo)
{
	pthread_create(&philo->thread[0], NULL, &check_is_dead, philo);
	pthread_create(&philo->thread[1], NULL, &check, philo);
	take_forks(philo);
}
