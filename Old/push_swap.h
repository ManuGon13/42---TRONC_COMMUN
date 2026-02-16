/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:22:09 by egonin            #+#    #+#             */
/*   Updated: 2026/02/04 11:52:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct	s_ps
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	size_max;
}	t_ps;

void	swap_top(int *tab, int size);
void	rotate_up(int *tab, int size);
void	rotate_down(int *tab, int size);
void	push_b(int *a, int *b, int *size_a, int *size_b);
void	push_a(int *a, int *b, int *size_a, int *size_b);
void	op_sa(t_ps *ps);
void	op_sb(t_ps *ps);
void	op_ss(t_ps *ps);
void	op_pa(t_ps *ps);
void	op_pb(t_ps *ps);
void	op_ra(t_ps *ps);
void	op_rb(t_ps *ps);
void	op_rr(t_ps *ps);
void	op_rra(t_ps *ps);
void	op_rrb(t_ps *ps);
void	op_rrr(t_ps *ps);
int	mapping_op(t_ps *ps, char *op);

#endif