/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:28:10 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 12:14:19 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	if (!a || !b)
		return (1);
	a->content = malloc(2 * sizeof(char));
	b->content = malloc(2 * sizeof(char));
	if (!a->content)
	{
		free(a);
		return (1);
	}
	if (!b->content)
	{
		free(b);
		return (1);
	}
	((char *)a->content)[0] = 'A';
	((char *)a->content)[1] = '\0';
	((char *)b->content)[0] = 'B';
	((char *)b->content)[1] = '\0';
	a->next = b;
	b->next = NULL;
	ft_lstclear(&a, del);
	printf("a = %p\n", (void *)a);
	return (0);
}
