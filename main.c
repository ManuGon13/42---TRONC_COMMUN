/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:20:57 by egonin            #+#    #+#             */
/*   Updated: 2026/02/16 18:00:29 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	count_numbers(int argc, char **argv, t_ps *ps)
{
	char	**result;
	int		i;

	i = 1;
	while (argv[i])
	{
		result = ft_split(argv[i]);
		j = 0;
		while (result[j])
		{
			ps->size_a++;
			free(result[j]);
			j++;
		}
		free(result);
		i++;
	}
	return (j);
}

void	allocate_stacks(t_ps *ps)
{
	ps->a = malloc(ps->size_a * sizeof(int));
	if (!ps->a)
		return (1);
	ps->b = malloc(ps->size_b * sizeof(int));
	if (!ps->b)
		return (1);
}

int	*parse_into_a(int argc, char **argv, t_ps *ps)
{
	int		i;
	int		j;
	int		x;
	long	num_conv;
	char	**result;

	i = 1;
	x = 0;
	j = 0;
	while (argv[i])
	{
		result = ft_split(argv[i]);
		j = 0;
		while (result[j])
		{
			num_conv = ft_atol(result[j], ps);
			if (check_doublon((int)num_conv, ps->a, x) == 1)
				error_n_free(ps);
			ps->a[x] = (int)num_conv;
			free(result[j]);
			j++;
			x++;
		}
		free(result);
		i++;
	}
	return (ps->a);
}

void	index_stack(t_ps *ps)
{
	int	*index_a;

	index_a = index_sorted(ps->a, ps->size_a);
	if (!index_a)
		error_n_free(ps);
	free(ps->a);
	ps->a = index_a;
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (0);
	ps = create_ps(argc, argv);
	count_numbers(argc, argv, ps);
	allocate_stacks(ps);
	parse_into_a(argc, argv, ps);
	index_stack(ps);
	if (is_sorted(ps->a, ps->size_a))
	{
		free_ps(ps);
		return (0);
	}
	if (ps->size_a <= 5)
		sort_small_stack(ps);
	else
		radix_sort(ps);
	free_ps(ps);
	return (0);
}
