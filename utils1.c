/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:18:13 by egonin            #+#    #+#             */
/*   Updated: 2026/02/16 17:40:09 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	error_n_free(t_ps *ps)
{
	free(ps->a);
	free(ps->b);
	free(ps);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_ps(t_ps *ps)
{
	free(ps->a);
	free(ps->b);
	free(ps);
}

int	ft_space(const char *c)
{
	if ((*c >= 9 && *c <= 13) || *c == 32)
		return (1);
	else
		return (0);
}

int	is_number(char *str, t_ps *ps)
{
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			error_n_free(ps);
		if (str[i] == '-' || str[i] == '+')
		{
			sign = 1;
			if (i != 0)
				error_n_free(ps);
		}
		if (sign == 1 && (str[i] < '0' || str[i] > '9'))
			error_n_free(ps);
		i++;
	}
	return (0);
}

long	ft_atol(const char *str, t_ps *ps)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_space(&str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		error_n_free(ps);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		error_n_free(ps);
	return (result * sign);
}
