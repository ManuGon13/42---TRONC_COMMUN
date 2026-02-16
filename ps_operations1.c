/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:08:32 by marvin            #+#    #+#             */
/*   Updated: 2026/02/04 10:08:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	op_sa(t_ps *ps)
{
	swap_top(ps->a, ps->size_a);
	write(1, "sa\n", 3);
}

void	op_sb(t_ps *ps)
{
	swap_top(ps->b, ps->size_b);
	write(1, "sb\n", 3);
}

void	op_ss(t_ps *ps)
{
	swap_top(ps->a, ps->size_a);
	swap_top(ps->b, ps->size_b);
	write(1, "ss\n", 3);
}

void	op_pa(t_ps *ps)
{
	push_a(ps->a, ps->b, &ps->size_a, &ps->size_b);
	write(1, "pa\n", 3);
}

void	op_pb(t_ps *ps)
{
	push_b(ps->a, ps->b, &ps->size_a, &ps->size_b);
	write(1, "pb\n", 3);
}
