/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:27:49 by egonin            #+#    #+#             */
/*   Updated: 2026/02/12 15:36:35 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	is_sorted(int *a, int size_a)
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
	if (*size_a == 2 && a[0] > a[1])
		swap_top(a, *size_a);
	else if (*size_a == 2 && a[0] < a[1])
		return ;
	if (*size_a == 3)
		sort_stackof_3(a, size_a);
	if (*size_a == 4 || *size_a == 5)
		sort_stackof_4or5(a, size_a, b, size_b);
}

static void	print_stack(char *name, int *tab, int size)
{
	int	i;

	i = 0;
	ft_printf("%s: ", name);
	while (i < size)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(void)
{
    int a1[3] = {2, 0, 1};
    int b1[3] = {0};
    int size_a1 = 3;
    int size_b1 = 0;

    ft_printf("=== Test 1: Tri de 3 elements ===\n");
    ft_printf("Avant: ");
    print_stack("A", a1, size_a1);
    sort_small_stack(a1, &size_a1, b1, &size_b1);
    ft_printf("Apres: ");
    print_stack("A", a1, size_a1);
    ft_printf("\n");

    int a2[4] = {3, 1, 0, 2};
    int b2[4] = {0};
    int size_a2 = 4;
    int size_b2 = 0;

    ft_printf("=== Test 2: Tri de 4 elements ===\n");
    ft_printf("Avant: ");
    print_stack("A", a2, size_a2);
    sort_small_stack(a2, &size_a2, b2, &size_b2);
    ft_printf("Apres: ");
    print_stack("A", a2, size_a2);
    ft_printf("\n");

    int a3[5] = {2, 1, 4, 0, 3};
    int b3[5] = {0};
    int size_a3 = 5;
    int size_b3 = 0;

    ft_printf("=== Test 3: Tri de 5 elements ===\n");
    ft_printf("Avant: ");
    print_stack("A", a3, size_a3);
    sort_small_stack(a3, &size_a3, b3, &size_b3);
    ft_printf("Apres: ");
    print_stack("A", a3, size_a3);

    return (0);
}