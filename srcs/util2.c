/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:24:13 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/07/24 17:52:59 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int					ft_nbrsize(long num)
{
	unsigned int	siz;

	siz = 1;
	while (num >= 10)
	{
		num /= 10;
		++siz;
	}
	return (siz);
}

char				*ft_itoa(long num)
{
	int				idx;
	int				siz;
	char			*str;

	idx = 0;
	siz = ft_nbrsize(num);
	str = (char *)malloc(siz + 1);
	if (!str)
		return (NULL);
	str[siz] = '\0';
	while (siz > idx)
	{
		--siz;
		str[siz] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

void				ft_usleep(int tim)
{
	long			stt;

	stt = ft_time_now();
	while (ft_time_now() < stt + tim)
		usleep(10);
}
