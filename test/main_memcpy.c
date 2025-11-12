/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:19:49 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 16:05:49 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	dest[] = "abcdef";
	char	src[] = "qwerty";
	ft_memcpy(dest, src, 4);
	printf("%s\n", dest);
	return 0;
}
