/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:53:30 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/07/24 18:31:47 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void				*ft_monitor_die(void *arg)
{
	t_philo			*phl;

	phl = (t_philo *)arg;
	if (phl->st_all->c_meal > 0)
	{
		while (ft_check_alive(phl) && ft_check_hungry(phl))
			if (ft_check_dead(phl))
				break ;
	}
	else
	{
		while (ft_check_alive(phl))
			if (ft_check_dead(phl))
				break ;
	}
	return (NULL);
}

void				ft_monitor_dead(t_all *all)
{
	while (!all->is_die)
		usleep(100);
}

void				ft_monitor_meal_dead(t_all *all)
{
	char			*tim;

	while (!all->is_die && all->c_fini < all->ph_cnt)
		usleep(100);
	if (all->c_fini == all->ph_cnt && !all->is_die)
	{
		tim = ft_itoa(ft_time_elapsed(all->tm_stt));
		printf(ANSI_BOL "[%s]\t", tim);
		printf("Each philosopher have eat %d times.\n" ANSI_RES, all->c_meal);
		free(tim);
	}
}