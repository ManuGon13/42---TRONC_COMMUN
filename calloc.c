/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:48:43 by egonin            #+#    #+#             */
/*   Updated: 2025/11/06 12:18:35 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	*calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*p;
	size_t			total;

	total = nmemb * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	while (total > 0)
	{
		*p = 0;
		p++;
		total--;
	}
	return (ptr);
}

int	main(void)
{
	int	*tab;
	int	i;

	i = 0;
	tab = calloc(5, sizeof(int));
	if (!tab)
		return (1);
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	free(tab);
	return (0);
}
