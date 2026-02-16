/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:22:09 by egonin            #+#    #+#             */
/*   Updated: 2026/02/16 19:47:48 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_ps
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		size_max;
	char	**tmp_split;
}	t_ps;

void		allocate_stacks(t_ps *ps);
int			*bubble_sort_tab(int *tab, int size);
int			check_doublon(int x, int *tab, int j);
t_ps		*create_ps(int argc, char **argv);
int			count_numbers(int argc, char **argv, t_ps *ps);
int			count_nums(char *str);
void		error_n_free(t_ps *ps);
int			find_min_pos(int *a, int size_a);
void		free_split(char **split);
long		ft_atol(const char *str, t_ps *ps);
int			ft_space(const char *c);
char		**ft_split(char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		free_ps(t_ps *ps);
void		index_stack(t_ps *ps);
int			is_number(char *str, t_ps *ps);
int			*index_sorted(int *tab, int size);
int			is_sorted(int *a, int size_a);
int			mapping_op(t_ps *ps, char *op);
void		min_to_top(t_ps *ps);
char		*num_dup(char *str);
void		op_sa(t_ps *ps);
void		op_sb(t_ps *ps);
void		op_ss(t_ps *ps);
void		op_pa(t_ps *ps);
void		op_pb(t_ps *ps);
void		op_ra(t_ps *ps);
void		op_rb(t_ps *ps);
void		op_rr(t_ps *ps);
void		op_rra(t_ps *ps);
void		op_rrb(t_ps *ps);
void		op_rrr(t_ps *ps);
int			*parse_into_a(int argc, char **argv, t_ps *ps);
void		parse_into_a_helper(char **result, t_ps *ps, int *x);
void		push_b(int *a, int *b, int *size_a, int *size_b);
void		push_a(int *a, int *b, int *size_a, int *size_b);
void		rotate_up(int *tab, int size);
void		rotate_down(int *tab, int size);
void		sort_stackof_3(t_ps *ps);
void		sort_stackof_4or5(t_ps *ps);
void		sort_small_stack(t_ps *ps);
void		swap_top(int *tab, int size);
int			*tab_dup(int *tab, int size);
void		radix_sort(t_ps *ps);

#endif