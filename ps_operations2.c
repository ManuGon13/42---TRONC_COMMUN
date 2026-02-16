/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:14:15 by marvin            #+#    #+#             */
/*   Updated: 2026/02/04 10:14:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	op_ra(t_ps *ps)
{
	rotate_up(ps->a, ps->size_a);
	write(1, "ra\n", 3);
}

void	op_rb(t_ps *ps)
{
	rotate_up(ps->b, ps->size_b);
	write(1, "rb\n", 3);
}

void	op_rr(t_ps *ps)
{
	rotate_up(ps->a, ps->size_a);
	rotate_up(ps->b, ps->size_b);
	write(1, "rr\n", 3);
}

void	op_rra(t_ps *ps)
{
	rotate_down(ps->a, ps->size_a);
	write(1, "rra\n", 4);
}

void	op_rrb(t_ps *ps)
{
	rotate_down(ps->b, ps->size_b);
	write(1, "rrb\n", 4);
}
