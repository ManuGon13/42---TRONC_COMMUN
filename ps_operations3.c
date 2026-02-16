/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:28:30 by marvin            #+#    #+#             */
/*   Updated: 2026/02/04 10:28:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	op_rrr(t_ps *ps)
{
	rotate_down(ps->a, ps->size_a);
	rotate_down(ps->b, ps->size_b);
	write(1, "rrr\n", 4);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	mapping_op(t_ps *ps, char *op)
{
	if (!ft_strcmp(op, "pa"))
		op_pa(ps);
	else if (!ft_strcmp(op, "pb"))
		op_pb(ps);
	else if (!ft_strcmp(op, "ra"))
		op_ra(ps);
	else if (!ft_strcmp(op, "rb"))
		op_rb(ps);
	else if (!ft_strcmp(op, "rr"))
		op_rr(ps);
	else if (!ft_strcmp(op, "rra"))
		op_rra(ps);
	else if (!ft_strcmp(op, "rrb"))
		op_rrb(ps);
	else if (!ft_strcmp(op, "rrr"))
		op_rrr(ps);
	else if (!ft_strcmp(op, "sa"))
		op_sa(ps);
	else if (!ft_strcmp(op, "sb"))
		op_sb(ps);
	else if (!ft_strcmp(op, "ss"))
		op_ss(ps);
	else
		return (0);
	return (1);
}
