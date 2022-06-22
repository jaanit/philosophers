/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:58:55 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/22 04:28:47 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*fill_data(int ac, char **av)
{
	t_data	*s_data;

	s_data = (t_data *)malloc(sizeof(t_data));
	s_data->num_philos = ft_atoi(av[1]);
	s_data->time_to_die = ft_atoi(av[2]);
	s_data->time_to_eat = ft_atoi(av[3]);
	s_data->time_to_sleep = ft_atoi(av[4]);
	(*s_data).tim_to_must_eat = -1;
	if (ac == 6)
		(*s_data).tim_to_must_eat = ft_atoi(av[5]);
	return (s_data);
}

t_philos	*fill_philos(t_data	*data)
{
	t_philos	*s_philo;
	int			i;

	data->forks = (pthread_mutex_t *) \
	malloc(sizeof(pthread_mutex_t) * data->num_philos);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	s_philo = (t_philos *)malloc(sizeof(t_philos) * data->num_philos);
	i = 0;
	while (i < data->num_philos)
	{
		s_philo[i].id = i;
		s_philo[i].s_data = data;
		s_philo[i].last_time_eat = get_time();
		s_philo[i].nbr_to_eat = 0;
		i++;
	}
	return (s_philo);
}

int	lancer_thread(t_philos *philos)
{
	pthread_t	*thread;
	int			i;

	i = 0;
	thread = malloc(sizeof(pthread_t) * philos->s_data->num_philos);
	while (i < philos->s_data->num_philos)
	{
		if (i == 0)
			philos->s_data->time_start = get_time();
		pthread_create(&thread[i], NULL, &activity, &philos[i]);
		usleep(1);
		i++;
	}
	while (check_is_dead(philos))
		;
	while(1);
	return (0);
}
