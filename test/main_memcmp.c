/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:39:35 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 16:09:01 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	const char	s1[] = "Hello";
	const char	s2[] = "Hallo";

	printf("la difference est: %d\n", ft_strncmp(s1, s2, 5));
	return (0);
}
