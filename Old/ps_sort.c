/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:27:49 by egonin            #+#    #+#             */
/*   Updated: 2026/02/04 18:38:24 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	is_sorted(int *a, int *size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (a[i] > a[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

void sort_stackof_3(int *a, int *size_a)
{
	index_sorted(a, size_a);
	if (a[0] == 2)
	{
		rotate_up(a, size_a);
		if (a[1] == 0)
			swap_top(a, size_a);
	}
	if (a[1] == 2)
	{
		rotate_down(a, size_a);
		if (a[1] == 0)
			swap_top(a, size_a);
	}
	if (a[2] == 2)
	{
		if (a[1] == 0)
			swap_top(a, size_a);
	}
}

int	find_min_pos(int *a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a )
	{
		if (a[i] == 0)
			return (i);
		i++;
	}
	return(- 1);
}

void	min_to_top(int *a, int size_a)
{
	int	i;
	int	min_pos;

	min_pos = find_min_pos(a, size_a);
	if ( min_pos <= size_a / 2)
	{
		while (0 < min_pos)
		{
			rotate_up(a, size_a);
			min_pos--;
		}
	}
	else
		while (min_pos < size_a)
		{
			rotate_down(a, size_a);
			min_pos++;
		}
}
void sort_stackof_4or5(int *a, int *size_a, int *b, int *size_b)
{
	while (*size_a > 3)
	{
		min_to_top(a, *size_a);
		push_b(a, b, size_a, size_b);
	}
	while (*size_b > 0)
		push_a(a, b, size_a, size_b);
}	



void sort_small_stack(int *a, int *size_a, int *b, int *size_b)
{

	if (size_a == 2 && a[0] < a[1])
		swap_top(a, size_a);
	else if (size_a == 2 && a[0] > a[1])
		return ;
	if (size_a == 3)
		sort_stackof_3(a, size_a);
	if (size_a == 4 || size_a == 5)
		sort_stackof_4or5(a, size_a);