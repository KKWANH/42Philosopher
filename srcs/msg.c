/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:04:54 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/07/24 19:27:18 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void				ft_msg_0(char *m, t_philo *phl, char *c, int *i)
{
	int				j;
	char			*t;

	j = 0;
	t = ft_itoa(ft_time_elapsed(phl->st_all->tm_stt));
	while (j < ft_strlen(c))
		m[(*i)++] = c[j++];
	j = 0;
	m[(*i)++] = '[';
	while (t[j])
		m[(*i)++] = t[j++];
	m[(*i)++] = ']';
	m[(*i)++] = '\t';
	m[(*i)++] = '[';
	free(t);
}

void				ft_msg_prt(t_philo *phl, char *c, char *stt, int i)
{
	char			*ide;
	char			msg[100];
	int				j;

	j = 0;
	pthread_mutex_lock(&phl->st_all->printr);
	ide = ft_itoa(phl->ph_idx);
	ft_msg_0(msg, phl, c, &i);
	while (ide[j])
		msg[i++] = ide[j++];
	j = 0;
	while (stt[j])
		msg[i++] = stt[j++];
	j = 0;
	c = ANSI_RES;
	while (j < ft_strlen(c))
		msg[i++] = c[j++];
	msg[i] = '\0';
	if ((phl->st_all->c_meal > 0 && phl->st_all->ph_cnt != phl->st_all->c_fini
		&& phl->status != DIE && phl->st_all->is_end != 1)
		|| !phl->st_all->is_die)
		write(1, msg, i);
	pthread_mutex_unlock(&phl->st_all->printr);
	free(ide);
}

void				ft_msg_select(t_philo *phl)
{
	if ((phl->st_all->c_meal > 0 &&
		phl->st_all->ph_cnt != phl->st_all->c_fini
		&& !phl->st_all->is_die) ||
		(!phl->st_all->is_die && phl->st_all->c_meal == 0))
	{
		if (phl->status == TAK)
			ft_msg_prt(phl, ANSI_CYA, "] has taken a fork.\n", 0);
		else if (phl->status == THK)
			ft_msg_prt(phl, ANSI_YEL, "] is thinking.\n", 0);
		else if (phl->status == EAT)
			ft_msg_prt(phl, ANSI_GRE, "] is eating.\n", 0);
		else if (phl->status == SLP)
			ft_msg_prt(phl, ANSI_BLU, "] is sleeping.\n", 0);
		else if (phl->status == DIE)
			ft_msg_prt(phl, ANSI_RED, "] is dead now. :(\n", 0);
	}
}
