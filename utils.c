/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:18:13 by egonin            #+#    #+#             */
/*   Updated: 2026/02/03 17:33:22 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void	error_n_free(t_ps *ps)
{
	free(ps->a);
	free(ps->b);
	free(NULL);
	ps->a = NULL;
	ps->b = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->size_max = 0;
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_space(const char *c)
{
	if ((*c >= 9 && *c <= 13) || *c == 32)
		return (1);
	else
		return (0);
}

int	is_number(char *str, t_ps *ps)
{
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			error_n_free(ps);
		if (str[i] == '-' || str[i] == '+')
		{
			sign = 1;
			if (i != 0)
				error_n_free(ps);
		}
		if (sign == 1 && (str[i] < '0' || str[i] > '9'))
			error_n_free(ps);
		i++;
	}
	return (0);
}

long	ft_atol(const char *str, t_ps *ps)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_space(&str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		error_n_free(ps);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		error_n_free(ps);
	return (result * sign);
}

int	count_nums(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (count);
}

char	*num_dup(char *str)
{
	int		i;
	int		len;
	char	*num_char;

	i = 0;
	len = 0;
	while (str[len] && str[len] != ' ')
		len++;
	num_char = malloc((len + 1) * sizeof(char));
	if (!num_char)
		return (NULL);
	while (i < len)
	{
		num_char[i] = str[i];
		i++;
	}
	num_char[i] = '\0';
	return (num_char);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	char	**nums_char;

	i = 0;
	j = 0;
	nums_char = malloc((count_nums(str) + 1) * sizeof(char *));
	if (!nums_char)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
		{
			nums_char[j] = num_dup(&str[i]);
			j++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	nums_char[j] = NULL;
	return (nums_char);
}

int	*tab_dup(int *tab, int size)
{
	int		i;
	int		*copy;

	i = 0;
	copy = malloc((size) * sizeof(int));
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = tab[i];
		i++;
	}
	return (copy);
}

int	*bubble_sort_tab(int *tab, int size)
{
	int	*sort_copy;
	int	i;
	int	j;
	int	tmp;

	i = 0;
	sort_copy = tab_dup(tab, size);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (sort_copy[j] > sort_copy[j + 1])
			{
				tmp = sort_copy[j + 1];
				sort_copy[j + 1] = sort_copy[j];
				sort_copy[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return(sort_copy);
}

int	*index_sorted(int *tab, int size)
{
	int	*index_tab;
	int	*sort_copy;
	int	i;
	int	j;
	int	count;

	i = 0;
	sort_copy  = bubble_sort_tab(tab, size);
	index_tab = tab_dup(tab, size);
	while (i < size)
	{
		j = 0;
		count = 0;
		while (j < size && count == 0)
		{
			if ( tab[i] == sort_copy[j])
			{	
				index_tab[i] = j;
				count++;
			}
			j++;
		}
		i++;
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

/*void print_tab(const char *name, int *tab, int size)
{
    int i = 0;
    printf("%s: ", name);
    while (i < size)
    {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");
}*/
int	main(int argc, char **argv)
{
	char	**result;
	long	num_conv;
	int		*index_a;
	int		i;
	int		x;
	int		j;
	t_ps	*ps;

	i = 1;
	j = 0;
	x = 0;
	if (argc == 1)
		return(write(1, "\n", 1));
	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (1);
	ps->a = NULL;
	ps->b = NULL;
	ps->size_a = 0;
	ps->size_b = 0;
	ps->size_max = 0;
	while (argv[i])
	{
		result = ft_split(argv[i]);
		j = 0;
		while (result[j])
		{
			ps->size_a++;
			free(result[j]);
			j++;
		}
		free(result);
		i++;
	}
	ps->a = malloc(ps->size_a * sizeof(int));
	if (!ps->a)
		return(1);
	i = 1;
	while (argv[i])
	{
		result = ft_split(argv[i]);
		j= 0;
		while (result[j])
		{
			num_conv = ft_atol(result[j], ps);
			if (check_doublon((int)num_conv, ps->a, x) == 1)
				error_n_free(ps);
			ps->a[x] = (int)num_conv;
			free(result[j]);
			j++;
			x++;
		}
		free(result);
		i++;
	}
	/*print_tab("A avant", ps->a, ps->size_a);/*TEST*/
	index_a = index_sorted(ps->a, ps->size_a);
	if (!index_a)
		error_n_free(ps);
	free(ps->a);
	ps->a = index_a;
	/*print_tab("Index", index_a, ps->size_a);/*TEST*/
	return (0);
}


