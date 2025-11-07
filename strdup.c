/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:22:16 by egonin            #+#    #+#             */
/*   Updated: 2025/11/07 14:15:44 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
	len = 0;
	while (s [len])
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(void)
{
	char	*src;
	char	*dup;

	src = "Hello 42";
	dup = strdup(src);
	printf("%s\n", dup);
	free(dup);
	return (0);
}
