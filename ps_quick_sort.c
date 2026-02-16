/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:27:49 by egonin            #+#    #+#             */
/*   Updated: 2026/02/16 19:40:50 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void	sort_stackof_3(t_ps *ps)
{
	if (is_sorted(ps->a, ps->size_a) == 0)
		return ;
	if (ps->a[0] > ps->a[1] && ps->a[0] < ps->a[2])
		op_sa(ps);
	else if (ps->a[0] > ps->a[1] && ps->a[1] > ps->a[2])
	{
		op_sa(ps);
		op_rra(ps);
	}
	else if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
		op_ra(ps);
	else if (ps->a[0] < ps->a[1] && ps->a[1] > ps->a[2] && ps->a[0] < ps->a[2])
	{
		op_sa(ps);
		op_ra(ps);
	}
	else if (ps->a[0] < ps->a[1] && ps->a[0] > ps->a[2])
		op_rra(ps);
}

int	find_min_pos(int *a, int size_a)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	if (size_a <= 0)
		return (-1);
	while (i < size_a)
	{
		if (a[i] < a[min])
			min = i;
		i++;
	}
	return (min);
}

void	min_to_top(t_ps *ps)
{
	int	moves;
	int	min_pos;

	if (is_sorted(ps->a, ps->size_a) == 0)
		return ;
	min_pos = find_min_pos(ps->a, ps->size_a);
	if (min_pos <= ps->size_a / 2)
	{
		while (min_pos > 0)
		{
			op_ra(ps);
			min_pos--;
		}
	}
	else
	{
		moves = ps->size_a - min_pos;
		while (moves > 0)
		{
			op_rra(ps);
			moves--;
		}
	}
}	

void	sort_stackof_4or5(t_ps *ps)
{
	while (ps->size_a > 3)
	{
		min_to_top(ps);
		op_pb(ps);
	}
	sort_stackof_3(ps);
	if (ps->size_b == 2 && ps->b[0] < ps->b[1])
		op_sb(ps);
	while (ps->size_b > 0)
		op_pa(ps);
}	

void	sort_small_stack(t_ps *ps)
{
	if (ps->size_a == 2)
	{
		if (ps->a[0] > ps->a[1])
			op_sa(ps);
		else if (ps->a[0] < ps->a[1])
			return ;
	}
	if (ps->size_a == 3)
		sort_stackof_3(ps);
	if (ps->size_a == 4 || ps->size_a == 5)
		sort_stackof_4or5(ps);
}
