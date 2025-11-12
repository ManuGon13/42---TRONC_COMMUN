/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:50:36 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 12:12:42 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew("A");
	b = ft_lstnew("B");
	c = ft_lstnew("C");
	a->next = b;
	b->next = c;
	printf("taille de la liste : %d\n", ft_lstsize(a));
	return (0);
}
