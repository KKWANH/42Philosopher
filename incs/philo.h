/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:43:30 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/07/24 21:01:32 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** includes
*/

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <errno.h>

/*
** definitions - color codes
*/

# define ANSI_RES	"\x1b[0m"
# define ANSI_BOL	"\x1b[1m"
# define ANSI_ITA	"\x1b[3m"
# define ANSI_RED	"\x1b[31m"
# define ANSI_GRE	"\x1b[32m"
# define ANSI_YEL	"\x1b[33m"
# define ANSI_BLU	"\x1b[34m"
# define ANSI_MAG	"\x1b[35m"
# define ANSI_CYA	"\x1b[36m"

/*
** definitions - struct
*/

typedef enum		e_status
{
	THK,
	DIE,
	TAK,
	EAT,
	SLP
}					t_status;

typedef struct		s_philo
{
	int				ph_idx;
	t_status		status;
	int				cn_eat;
	long			tm_eat;
	pthread_mutex_t	*lf_stk;
	pthread_mutex_t	*rg_stk;
	struct s_all	*st_all;
}					t_philo;

typedef struct		s_all
{
	int				ph_cnt;
	int				tm_die;
	int				tm_eat;
	int				tm_slp;
	int				c_meal;
	int				c_fini;
	int				is_die;
	long			tm_stt;
	t_philo			*philos;
	pthread_mutex_t	*sticks;
	pthread_mutex_t	printr;
	pthread_mutex_t	f_meal;
	pthread_mutex_t	ph_die;
	int				is_end;
}					t_all;

/*
** functions - init.c
*/

int					ft_init_check_param(int arc, char **arv);
int					ft_init_philos(t_all *all);
int					ft_init_sticks(t_all *all);
int					ft_init_mutex(t_all *all);
int					ft_init(t_all *all, int arc, char **arv);

/*
** functions - exit.c
*/

void				ft_free_mutex(t_all *all);
void				ft_free_sticks(t_all *all);
void				ft_free_philo(t_all *all);
int					ft_clear(t_all *all);
int					ft_error(int opt);

/*
** functions - time.c
*/

long				ft_time_now(void);
long				ft_time_elapsed(long stt);

/*
** functions - check.c
*/

int					ft_check_alive(t_philo *phl);
int					ft_check_hungry(t_philo *phl);
int					ft_check_dead(t_philo *phl);
int					ft_check_eat_enough(t_philo *phl);

/*
** functions - monitor.c
*/

void				*ft_monitor_die(void *arg);
void				ft_monitor_dead(t_all *all);
void				ft_monitor_meal_dead(t_all *all);

/*
** functions - msg.c
*/

void				ft_msg_prt(t_philo *phl, char *c, char *stt, int i);
void				ft_msg_select(t_philo *phl);

/*
** functions - start.c
*/

void				ft_start_lock_sticks(t_philo *phl);
void				ft_start_eat(t_philo *phl);
void				ft_start_unlock_sticks(t_philo *phl);
void				ft_start_thk(t_philo *phl);
void				ft_start(t_philo *phl);

/*
** functions - util1.c
*/

int					ft_strlen(char *str);
int					ft_putstr(char *str);
int					ft_atoi_sub(char *str, int rst, int neg);
int					ft_atoi(char *str);
int					ft_is_number(char *num);

/*
** functions - util2.c
*/

int					ft_nbrsize(long num);
char				*ft_itoa(long num);
void				ft_usleep(int tim);

#endif
