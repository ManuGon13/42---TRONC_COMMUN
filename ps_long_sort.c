/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_long_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:41:28 by egonin            #+#    #+#             */
/*   Updated: 2026/02/12 14:39:06 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	radix_sort(t_ps *ps)
{
	int	i;
	int	j;
	int	max;
	int	max_bits;
	int	n;

	if (!ps || ps->size_a < 2)
		return ;
	max = ps->size_a - 1;
	max_bits = 0;
	i = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		n = ps->size_a;
		j = 0;
		while (j < n)
		{
			if (((ps->a[0] >> i) & 1) == 0)
				op_pb(ps);
			else
				op_ra(ps);
			j++;
		}
		while (ps->size_b > 0)
			op_pa(ps);
		i++;
	}
}
