/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_long_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:41:28 by egonin            #+#    #+#             */
/*   Updated: 2026/02/16 20:06:37 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	find_max_pos(t_ps *ps)
{
	int	i;
	int	max_pos;
	int	max_val;

	i = 0;
	max_pos = 0;
	max_val = ps->b[0];
	while (i < ps->size_b)
	{
		if (ps->b[i] > max_val)
		{
			max_val = ps->b[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

void	push_max_to_a(t_ps *ps)
{
	int	max_pos;
	int	moves;

	max_pos = find_max_pos(ps);
	if (max_pos <= ps->size_b / 2)
	{
		moves = max_pos;
		while (moves-- > 0)
			op_rb(ps);
	}
	else
	{
		moves = ps->size_b - max_pos;
		while (moves-- > 0)
			op_rrb(ps);
	}
	op_pa(ps);
}

void	chunk_sort(t_ps *ps)
{
	int	chunk_size;
	int	chunk_count;
	int	pushed;

	if (ps->size_a <= 100)
		chunk_count = 5;
	else if (ps->size_a <= 250)
		chunk_count = 8;
	else
		chunk_count = 11;
	chunk_size = ps->size_a / chunk_count;
	pushed = 0;
	while (ps->size_a > 0)
	{
		if (ps->a[0] <= pushed + chunk_size || ps->size_a == 1)
		{
			op_pb(ps);
			if (ps->size_b > 1 && ps->b[0] < pushed + chunk_size / 2)
				op_rb(ps);
			pushed++;
		}
		else
			op_ra(ps);
	}
	while (ps->size_b > 0)
		push_max_to_a(ps);
}

void	radix_sort(t_ps *ps)
{
	if (!ps || ps->size_a < 2)
		return ;
	chunk_sort(ps);
}
