/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 03:40:16 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/22 04:34:16 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_num(t_data *s_data)
{
	if (s_data->num_philos <= 0 || s_data->time_to_die <= 0 \
	|| s_data->time_to_sleep <= 0 || s_data->time_to_eat <= 0)
	{
		printf("EROOR : invalide time\n");
		return (0);
	}
	return (1);
}

int	ft_check_input(int ac, char **av)
{
	int		i;
	int		j;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		printf("ERROR_ARGUMENT : saisie 5 ou 6 argument");
		return (0);
	}
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("ERROR_ARGUMENT : chiffres uniquement");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data		*data;

	if (!ft_check_input(ac, av))
		return (0);
	data = fill_data(ac, av);
	if (!check_num(data))
		return (0);
	lancer_process(data);
	end_philo(data);
	return (0);
}
