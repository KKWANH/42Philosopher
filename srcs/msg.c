/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:04:54 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/07/24 18:37:35 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void				ft_msg_0(char *m, char *t, char *c, int *i)
{
	int				j;

	j = 0;
	while (j < ft_strlen(c))
		m[(*i)++] = c[j++];
	j = 0;
	m[(*i)++] = '[';
	while (t[j])
		m[(*i)++] = t[j++];
	m[(*i)++] = ']';
	m[(*i)++] = '\t';
	m[(*i)++] = '[';
}

void				ft_msg_prt(t_philo *phl, char *c, char *stt, int i, int j)
{
	char			*tim;
	char			*ide;
	char			msg[100];

	pthread_mutex_lock(&phl->st_all->printr);
	tim = ft_itoa(ft_time_elapsed(phl->st_all->tm_stt));
	ide = ft_itoa(phl->ph_idx);
	ft_msg_0(msg, tim, c, &i);
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
	free(tim);
}

void				ft_msg_select(t_philo *phl)
{
	if ((phl->st_all->c_meal > 0 &&
		phl->st_all->ph_cnt != phl->st_all->c_fini
		&& !phl->st_all->is_die) ||
		(!phl->st_all->is_die && phl->st_all->c_meal == 0))
	{
		if (phl->status == TAK)
			ft_msg_prt(phl, ANSI_CYA, "] has taken a fork.\n", 0, 0);
		else if (phl->status == THK)
			ft_msg_prt(phl, ANSI_YEL, "] is thinking.\n", 0, 0);
		else if (phl->status == EAT)
			ft_msg_prt(phl, ANSI_GRE, "] is eating.\n", 0, 0);
		else if (phl->status == SLP)
			ft_msg_prt(phl, ANSI_BLU, "] is sleeping.\n", 0, 0);
		else if (phl->status == DIE)
			ft_msg_prt(phl, ANSI_RED, "] is dead now. :(\n", 0, 0);
	}
}