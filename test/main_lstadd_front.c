/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:21:27 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 12:12:17 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*lst;
	t_list	*new;

	lst = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	if (!lst || !new)
		return (1);
	lst->content = malloc(20 * sizeof(char));
	new->content = malloc(20 * sizeof(char));
	if (!lst->content)
	{
		free(lst);
		return (1);
	}
	if (!new->content)
	{
		free(new);
		return (1);
	}
	lst->content = "A";
	new->content = "B";
	lst->next = new;
	new->next = NULL;
	ft_lstadd_front(&lst, new);
	printf("1er maillon : %s\n", (char *)lst->content);
	printf("suivant : %s\n", (char *)lst->next->content);
	return (0);
}
