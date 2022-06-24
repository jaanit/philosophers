/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:39:56 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/23 01:08:14 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*activity(void *data)
{
	t_philos	*philo;

	philo = (t_philos *)data;
	if (philo->id % 2)
		take_forks(philo);
	else
		star_thinking(philo);
	return (NULL);
}

int	check_is_dead(void *check)
{
	t_philos	*philo;
	int			i;

	philo = (t_philos *)check;
	i = 0;
	usleep(50);
	while (i < philo->s_data->num_philos)
	{
		if (get_time() - philo[i].last_time_eat > philo->s_data->time_to_die)
		{		
			printf("%llu philo %d died\n", get_time() - \
			philo->s_data->time_start, philo->id + 1);
			return (0);
		}
		i++;
	}
	if (check_final_eating(philo))
		return (0);
	return (1);
}
