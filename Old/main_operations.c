/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:52:10 by egonin            #+#    #+#             */
/*   Updated: 2026/02/04 11:55:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	swap_top(int *tab, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	if (size >= 2)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
}

void	rotate_up(int *tab, int size)
{ 
	int	tmp;
	int	i;

	if (size < 2)
		return ;
	tmp = tab[0];
	i = 0;
	while (i < size - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[size - 1] = tmp;
}

void	rotate_down(int *tab, int size)
{ 
	int	tmp;
	int	i;

	if (size < 2)
		return ;
	tmp = tab[size - 1];
	i = size -1;
	while (i > 0)
	{
		tab[i] = tab[i - 1];
		i--;
	}
	tab[0] = tmp;
}

void	push_b(int *a, int *b, int *size_a, int *size_b)
{
	int	tmp;
	int	i;
	
	if (*size_a == 0)
		return ;
	tmp = a[0];
	i = 0;
	while (i < *size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	(*size_a)--;
	i = *size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = tmp;
	(*size_b)++;
}

void	push_a(int *a, int *b, int *size_a, int *size_b)
{
	int	tmp;
	int	i;
	
	if (*size_b == 0)
		return ;
	tmp = b[0];
	i = 0;
	while (i < *size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*size_b)--;
	i = *size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = tmp;
	(*size_a)++;
}

int	main(void)
{
	int	i;
	t_ps ps;
	int a[] = {2, 9, 1, 7};
	int b[] = {0, 0, 0};

	ps.a = a;
	ps.b = b;
	i = 0;
	ps.size_a = 4;
	ps.size_b = 0;
	op_pb(&ps);
	while (i < ps.size_a)
    {
        printf("%d ", ps.a[i]);
        i++;
    }
	return (0);

}