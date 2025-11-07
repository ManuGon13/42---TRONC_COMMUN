/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:20:04 by egonin            #+#    #+#             */
/*   Updated: 2025/11/04 15:35:48 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char    *strdup(const char *s)
{
    char    *dup;
    size_t  i;
    size_t  len;

    i = 0;
    len = 0;
    while(s[len])
        len++;
    dup = malloc(len + 1);
    if (!dup)
        return(NULL)
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}