/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <egonin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:18:13 by egonin            #+#    #+#             */
/*   Updated: 2026/02/16 17:41:29 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
	return (sort_copy);
}
