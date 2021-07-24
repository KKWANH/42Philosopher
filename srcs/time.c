/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:14:24 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/07/20 11:53:39 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

long				ft_time_now(void)
{
	struct timeval	tim;
	long			end;

	gettimeofday(&tim, NULL);
	end = (tim.tv_sec * 1000) + (tim.tv_usec / 1000);
	return (end);
}

long				ft_time_elapsed(long stt)
{
	struct timeval	tim;
	long			end;

	gettimeofday(&tim, NULL);
	end = (tim.tv_sec * 1000) + (tim.tv_usec / 1000);
	return (end - stt);
}