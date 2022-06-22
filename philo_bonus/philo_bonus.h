/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:48:31 by rjaanit           #+#    #+#             */
/*   Updated: 2022/06/22 04:35:53 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_data
{
	long long	time_to_eat;
	long long	time_to_sleep;
	long long	time_to_die;
	long long	num_philos;
	long long	time_start;
	int			eat_count;
	int			tim_to_must_eat;
	sem_t		*sem_forks;
	sem_t		*sem_check;
	sem_t		*barage;
	int			dead;
}t_data;

typedef struct s_philos
{
	unsigned long long	last_time_eat;
	int					id;
	t_data				*s_data;
	int					nbr_to_eat;
	pid_t				pid;
	pthread_t			thread[2];
	int					status;
}t_philos;

t_philos			*fill_philos(int ac, char **av, t_data	*data);
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
void				star_thinking(t_philos *philo);
void				star_sleeping(t_philos *philo);
void				*check_is_dead(void *check);
int					check_final_eating(t_philos *philo);
int					lancer_process(t_data *data);
void				ft_philo(t_philos *philo);
void				end_philo(t_data *data);
#endif
