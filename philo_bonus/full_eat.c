/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:42:41 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/20 01:48:33 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_final_eating(t_philos *philo)
{
	if (philo->s_data->tim_to_must_eat < 0)
		return (0);
	if (philo->nbr_to_eat < philo->s_data->tim_to_must_eat)
		return (0);
	return (1);
}
