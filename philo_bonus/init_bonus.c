/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:58:55 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/22 03:28:15 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_data	*fill_data(int ac, char **av)
{
	t_data	*s_data;

	s_data = (t_data *)malloc(sizeof(t_data));
	s_data->num_philos = ft_atoi(av[1]);
	s_data->time_to_die = ft_atoi(av[2]);
	s_data->time_to_eat = ft_atoi(av[3]);
	s_data->time_to_sleep = ft_atoi(av[4]);
	s_data->tim_to_must_eat = -1;
	if (ac == 6)
		s_data->tim_to_must_eat = ft_atoi(av[5]);
	s_data->time_start = get_time();
	sem_unlink("/sem_forka");
	sem_unlink("/sem_check");
	sem_unlink("/barage");
	s_data->sem_forks = sem_open("/sem_forka", O_CREAT, 0, s_data->num_philos);
	s_data->sem_check = sem_open("/sem_check", O_CREAT, 0, 1);
	s_data->barage = sem_open("/barage", O_CREAT, 0, 0);
	return (s_data);
}

int	lancer_process(t_data *data)
{
	int			i;
	t_philos	*philos;

	philos = (t_philos *)malloc(sizeof(t_philos) * data->num_philos);
	i = -1;
	while (++i < data->num_philos)
	{
		philos[i].pid = fork();
		if (philos[i].pid == 0)
		{
			philos[i].s_data = data;
			philos[i].id = i;
			philos[i].last_time_eat = get_time();
			philos[i].nbr_to_eat = 0;
			philos[0].status = 0;
			ft_philo(&philos[i]);
			usleep(1);
			return (0);
		}
	}
	i = -1;
	while (++i < data->num_philos)
		waitpid(philos[i].pid, NULL, 0);
	free(philos);
	return (0);
}
