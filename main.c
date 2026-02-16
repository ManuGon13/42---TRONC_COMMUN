/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:20:57 by egonin            #+#    #+#             */
/*   Updated: 2026/02/16 20:44:43 by egonin           ###   ########.fr       */
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
	int		count;

	(void)argc;
	i = 1;
	while (argv[i])
	{
		result = ft_split(argv[i]);
		if (!result)
			error_n_free(ps);
		count = 0;
		while (result[count])
			count++;
		if (count == 0 && (free_split(result), 1))
			error_n_free(ps);
		ps->size_a += count;
		free_split(result);
		i++;
	}
	return (0);
}

void	parse_into_a_helper(char **result, t_ps *ps, int *x)
{
	int		j;
	long	num_conv;

	j = 0;
	while (result[j])
	{
		num_conv = ft_atol(result[j], ps);
		if (check_doublon((int)num_conv, ps->a, *x) == 1)
			error_n_free(ps);
		ps->a[*x] = (int)num_conv;
		(*x)++;
		j++;
	}
}

int	*parse_into_a(int argc, char **argv, t_ps *ps)
{
	int		i;
	int		x;
	char	**result;

	(void)argc;
	i = 1;
	x = 0;
	while (argv[i])
	{
		result = ft_split(argv[i]);
		if (!result)
			error_n_free(ps);
		ps->tmp_split = result;
		parse_into_a_helper(result, ps, &x);
		ps->tmp_split = NULL;
		free_split(result);
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
	if (!ps)
		error_n_free(ps);
	count_numbers(argc, argv, ps);
	if (ps->size_a == 0)
		error_n_free(ps);
	allocate_stacks(ps);
	parse_into_a(argc, argv, ps);
	index_stack(ps);
	if (is_sorted(ps->a, ps->size_a) == 0)
	{
		free_ps(ps);
		return (0);
	}
	if (ps->size_a <= 5)
		sort_small_stack(ps);
	else
		chunk_sort(ps);
	free_ps(ps);
	return (0);
}
