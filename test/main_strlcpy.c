/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:00:30 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 16:06:29 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char	src[] = "Hello, world!";
	char		dst[];
	size_t		size;

	dst[] = "Couco";
	size = ft_strlcpy(dst, src, sizeof (dst));
	printf("dst: %s\n", dst);
	printf("src length : %zu\n", size);
	return (0);
}
