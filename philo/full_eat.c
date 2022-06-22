/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:42:41 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/22 04:02:41 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_final_eating(t_philos *philo)
{
	int		i;

	i = 0;
	if (philo->s_data->tim_to_must_eat < 0)
		return (0);
	while (i < philo->s_data->num_philos)
	{
		if (philo[i].nbr_to_eat < philo->s_data->tim_to_must_eat)
			return (0);
		i++;
	}
	return (1);
}
