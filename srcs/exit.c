/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:59:04 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/07/24 20:42:08 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void				ft_free_mutex(t_all *all)
{
	if (pthread_mutex_destroy(&all->printr) == EBUSY)
	{
		pthread_mutex_unlock(&all->printr);
		pthread_mutex_destroy(&all->printr);
	}
	if (pthread_mutex_destroy(&all->f_meal) == EBUSY)
	{
		pthread_mutex_unlock(&all->f_meal);
		pthread_mutex_destroy(&all->f_meal);
	}
	if (pthread_mutex_destroy(&all->ph_die) == EBUSY)
	{
		pthread_mutex_unlock(&all->ph_die);
		pthread_mutex_destroy(&all->ph_die);
	}
}

void				ft_free_sticks(t_all *all)
{
	int				idx;

	idx = 0;
	while (idx < all->ph_cnt)
	{
		if (pthread_mutex_destroy(&all->sticks[idx]) == EBUSY)
		{
			pthread_mutex_unlock(&all->sticks[idx]);
			pthread_mutex_destroy(&all->sticks[idx]);
		}
		++idx;
	}
}

void				ft_free_philo(t_all *all)
{
	if (all->philos)
		free(all->philos);
}

int					ft_clear(t_all *all)
{
	usleep(1000 * 1000);
	ft_free_mutex(all);
	ft_free_sticks(all);
	ft_free_philo(all);
	return (1);
}

int					ft_error(int opt)
{
	printf(ANSI_RED "" ANSI_BOL "[ERROR] " ANSI_RES "" ANSI_BOL "" ANSI_YEL);
	if (opt == 0)
		printf("Invalid number of parameters. :(\n" ANSI_RES);
	if (opt == 1)
		printf("Invaild parameters :(\n" ANSI_RES);
	return (-1);
}
