/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:48:31 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/22 04:20:29 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t		*forks;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			time_to_die;
	long long			num_philos;
	long long			time_start;
	int					eat_count;
	int					tim_to_must_eat;
}t_data;

typedef struct s_philos
{
	long long		last_time_eat;
	int				id;
	t_data			*s_data;
	int				nbr_to_eat;
	int				is_eat;
}t_philos;

t_philos			*fill_philos(t_data	*data);
int					ft_check_input(int ac, char **av);
int					ft_isdigit(int str);
int					print_error(char *str);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *s);
t_data				*fill_data(int ac, char **av);
int					check_num(t_data *s_data);
long long			get_time(void);
void				print_message(char *str);
void				sleping_time(unsigned long long time);
void				*activity(void *data);
void				start_eating(t_philos *philo);
void				take_forks(t_philos *philo);
int					lancer_thread(t_philos *philos);
void				star_thinking(t_philos *philo);
void				star_sleeping(t_philos *philo);
int					check_is_dead(void *check);
int					check_final_eating(t_philos *philo);
void				ft_free(t_philos *philo, t_data *data);
#endif
