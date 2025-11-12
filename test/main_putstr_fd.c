/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_putstr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:02:15 by egonin            #+#    #+#             */
/*   Updated: 2025/11/11 12:49:08 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	main(void)
{
	char	s;

	s = "Allez l'OM";
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
