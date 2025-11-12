/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:31:17 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 16:06:42 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h> 
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char	src[] = " World";
	char		dst[];
	size_t		size;

	dst[] = "Hello";
	size = ft_strlcat(dst, src, sizeof (src) + sizeof(dst));
	printf("dst: %s\n", dst);
	printf("%zu\n", size);
	return (0);
}
