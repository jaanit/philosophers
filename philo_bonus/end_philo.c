/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:46:44 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/20 04:46:45 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_philo(t_data *data)
{
	sem_unlink("/sem_forka");
	sem_unlink("/sem_check");
	sem_close(data->sem_forks);
	sem_close(data->sem_check);
	free(data);
}
