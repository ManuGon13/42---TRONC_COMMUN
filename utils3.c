/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:18:13 by egonin            #+#    #+#             */
/*   Updated: 2026/02/16 18:00:16 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	*index_sorted(int *tab, int size)
{
	int	*index_tab;
	int	*sort_copy;
	int	i;
	int	j;
	int	count;

	i = 0;
	sort_copy = bubble_sort_tab(tab, size);
	index_tab = tab_dup(tab, size);
	while (i++ < size)
	{
		j = 0;
		count = 0;
		while (j++ < size && count == 0)
		{
			if (tab[i] == sort_copy[j])
			{	
				index_tab[i] = j;
				count++;
			}
		}
	}
	free(sort_copy);
	return (index_tab);
}

int	check_doublon(int x, int *tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (tab[i] == x)
			return (1);
		i++;
	}
	return (0);
}

t_ps	create_ps(int argc, char **argv)
{
	t_ps	*ps;

	(void)argc;
	(void)argv;
	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (1);
	ps->a = NULL;
	ps->b = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->size_max = 0;
	return (ps);
}
