/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:27:49 by egonin            #+#    #+#             */
/*   Updated: 2026/02/16 17:44:06 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void	sort_stackof_3(int *a, int *size_a)
{
	if (is_sorted(a, *size_a) == 0)
		return ;
	if (a[0] > a[1] && a[0] < a[2])
		swap_top(a, *size_a);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		swap_top(a, *size_a);
		rotate_down(a, *size_a);
	}
	else if (a[0] > a[1] && a[0] > a[2])
		rotate_up(a, *size_a);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		swap_top(a, *size_a);
		rotate_up(a, *size_a);
	}
	else if (a[0] < a[1] && a[0] > a[2])
		rotate_down(a, *size_a);
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

void	min_to_top(int *a, int size_a)
{
	int	moves;
	int	min_pos;

	if (is_sorted(a, size_a) == 0)
		return ;
	min_pos = find_min_pos(a, size_a);
	if (min_pos <= size_a / 2)
	{
		while (min_pos > 0)
		{
			rotate_up(a, size_a);
			min_pos--;
		}
	}
	else
	{
		moves = size_a - min_pos;
		while (moves > 0)
		{
			rotate_down(a, size_a);
			moves--;
		}
	}
}	

void	sort_stackof_4or5(int *a, int *size_a, int *b, int *size_b)
{
	while (*size_a > 3)
	{
		min_to_top(a, *size_a);
		push_b(a, b, size_a, size_b);
	}
	sort_stackof_3(a, size_a);
	if (*size_b == 2 && b[0] < b[1])
		swap_top(b, *size_b);
	while (*size_b > 0)
		push_a(a, b, size_a, size_b);
}	

void	sort_small_stack(int *a, int *size_a, int *b, int *size_b)
{
	if (*size_a == 2)
	{
		if (a[0] > a[1])
			swap_top(a, *size_a);
		else if (a[0] < a[1])
			return ;
	}
	if (*size_a == 3)
		sort_stackof_3(a, size_a);
	if (*size_a == 4 || *size_a == 5)
		sort_stackof_4or5(a, size_a, b, size_b);
}
