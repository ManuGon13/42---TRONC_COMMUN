/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:18:13 by egonin            #+#    #+#             */
/*   Updated: 2026/02/02 17:41:10 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>

void	error_n_free(t_ps *ps)
{
	free(ps->a);
	free(ps->b);
	free(NULL);
	a = NULL;
	b = NULL;
	size_a = 0;
	size_b = 0;
	size_max = 0;
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_space(const char *c)
{
	if ((*c >= 9 && *c <= 13) || *c == 32)
		return (1);
	else
		return (0);
}

int	is_number(char *str)
{
	int		i;
	int		sign;
	t_ps	*ps;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			error(ps);
		if (str[i] == '-' || str[i] == '+')
		{
			sign = 1;
			if (i != 0)
				error(ps);
		}
		if (sign == 1 && (str[i] <= '0' || str[i] >= '9'))
			error(ps);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		i;
	t_ps	*ps;
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
		else if (str[i] == '+')
			sign = 1;
		i++;
	}
	if (str[i] <= '0' || str[i] >= '9')
		error(ps);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		error(ps);
	else
		return (result * sign);
}
int	count_nums(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == " ")
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != " ")
				i++;
		}
	}
	return (count);
}

char	*num_dup(char *str)
{
	int		i;
	int		len;
	char	*num_char;

	i = 0;
	len = 0;
	while (str[len] && str[len] != " ")
		len++;
	num_char = malloc((len + 1) * sizeof(int));
	if (!num_char)
		return (NULL);
	while (i < len)
	{
		num_char[i] = str[i];
		i++;
	}
	num_char[i] = '\0';
	return (num_char);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	char	**nums_char;

	i = 0;
	j = 0;
	nums_char = malloc((count_nums(str) + 1) * sizeof(int));
	if (!nums_char)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == " ")
			i++;
		if (str[i])
		{
			nums_char[j] = num_dup(&str[i]);
			j++;
			while (str[i] && str[i] != " ")
				i++;
		}
	}
	nums_char[j] = NULL;
	return (nums_char);
}

int	main(int argc, char **argv)
{
	char	**result;
	int		i;

	i = 1;
	if (argc == 1)
		return(write(1, "\n", 1));
	result = ft_split(argv[i]);
	while (result[i])
	{
		printf("[%s]\n", result[i]);
		i++;
	}
	return (0);
}