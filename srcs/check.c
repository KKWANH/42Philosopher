/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:35:25 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/07/24 19:18:33 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int					ft_check_alive(t_philo *phl)
{
	if (phl->status != DIE && !phl->st_all->is_die)
		return (1);
	return (0);
}

int					ft_check_hungry(t_philo *phl)
{
	if (phl->cn_eat < phl->st_all->c_meal)
		return (1);
	return (0);
}

int					ft_check_dead(t_philo *phl)
{
	long			tim;

	tim = ft_time_elapsed(phl->st_all->tm_stt);
	if ((phl->st_all->tm_die < tim - phl->tm_eat) && (phl->status != EAT))
	{
		phl->status = DIE;
		ft_msg_select(phl);
		pthread_mutex_lock(&phl->st_all->ph_die);
		phl->st_all->is_die = 1;
		pthread_mutex_unlock(&phl->st_all->ph_die);
		return (1);
	}
	usleep(100);
	return (0);
}

int					ft_check_eat_enough(t_philo *phl)
{
	if (phl->cn_eat == phl->st_all->c_meal)
		return (1);
	return (0);
}
