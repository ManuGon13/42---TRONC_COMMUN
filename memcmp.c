/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:39:35 by egonin            #+#    #+#             */
/*   Updated: 2025/11/06 11:38:25 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*st1 = (const unsigned char *)s1;
	const unsigned char	*st2 = (const unsigned char *)s2;
	size_t				i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (st1[i] != st2[i])
			return ((int)(st1[i] - st2[i]));
		i++;
	}
	return (0);
}

/*int	main(void)
{
	const char	s1[] = "Hello";
	const char	s2[] = "Hallo";

	printf("la difference est: %d\n", strncmp(s1, s2, 5));
	return (0);
}*/
