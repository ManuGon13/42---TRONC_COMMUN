/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:31:17 by egonin            #+#    #+#             */
/*   Updated: 2025/11/06 11:35:44 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> 
#include <stdio.h>

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	i = 0;
	dlen = 0;
	slen = 0;
	while (dst[dlen] && dlen < size)
		dlen++;
	while (src[slen])
		slen++;
	if (dlen == size)
		return (size + slen);
	while (src[i] && dlen + i < size - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}

/*int	main(void)
{
	const char	src[] = " World";
	char		dst[];
	size_t		size;

	dst[] = "Hello";
	size = strlcat(dst, src, sizeof (src) + sizeof(dst));
	printf("dst: %s\n", dst);
	printf("%zu\n", size);
	return (0);
}*/
