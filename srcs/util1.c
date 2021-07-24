#include "../incs/philo.h"

int					ft_strlen(char *str)
{
	int				cnt;

	cnt = 0;
	while (str[cnt])
		++cnt;
	return (cnt);
}

int					ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int					ft_atoi_sub(char *str, int rst, int neg)
{
	int				idx;

	idx = 0;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		rst = ((rst * 10) + (str[idx] - 48));
		++idx;
		if (((rst == 214748364 && str[idx] >= '8') ||
					(rst > 214748364 && str[idx] > '0')) && neg == 0)
			return (-1);
		if (((rst == 214748364 && str[idx] >= '9') ||
					(rst > 214748364 && str[idx] > '0')) && neg == 1)
			return (0);
	}
	if (neg == 1)
		rst *= -1;
	return (rst);
}

int					ft_atoi(char *str)
{
	int				idx;
	int				rst;

	idx = 0;
	rst = 0;
	while ((*str == '\t') || (*str == '\n') || (*str == '\v')
		|| (*str == '\f') || (*str == '\r') || (*str == ' '))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			++idx;
		++str;
	}
	if (*str < '0' || *str > '9')
		return (0);
	return (ft_atoi_sub(str, rst, idx));
}

int					ft_is_number(char *num)
{
	int				idx;

	idx = 0;
	if (num[idx] != '\0')
	{
		while (num[idx])
			if (num[idx] == '+' || num[idx] == '-')
				++idx;
			else
				break ;
		while (num[idx])
			if (num[idx] >= '0' || num[idx] <= '9')
				++idx;
			else
				return (-1);
		return (1);
	}
	return (-1);
}