/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:18:35 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 12:47:01 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*src;
	char	*dup;

	src = "Bonjour";
	dup = ft_substr(src, 3, 4);
	printf("%s\n", dup);
	free(dup);
	return (0);
}
