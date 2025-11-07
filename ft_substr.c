
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egonin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:18:35 by egonin            #+#    #+#             */
/*   Updated: 2025/11/07 17:41:12 by egonin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dup;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > strlen(s))
	{
		dup = malloc(1);
		if (!dup)
			return (NULL);
		dup[0] = '\0';
	}
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i + start];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(void)
{
	char	*src;
	char	*dup;

	src = "Bonjour";
	dup = ft_substr(src, 3, 4);
	printf("%s\n", dup);
	free(dup);
	return (0);
=======
#include <string.h>
#include <stdio.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *sub;
        size_t  i;
        size_t  s_len;

        i = 0;
        if (s == '\0')
            return (NULL)
        s_len = 0;
        while (s[s_len])
            s_len++;
        if (start >= s_len)
        {
            sub = malloc (1);
            if (!sub)
                return (NULL);
            sub[0] = '\0';
            return (sub);
        }
        if (len > s_len - start)
            len = s_len - start;
        sub = malloc(len + 1);
        if (!sub)
            return (NULL);
        while (i < len && s[start + i])
        {
            sub[i] = s[start + i];
            i++;
        }
        sub[i] = '\0';
        return (sub);
}

int     main(void)
{
    char const      *c;

    c[] = "Bonjour";
    printf("%s\n", ft_substr(c, 3, 4));
    return (0);
>>>>>>> 02d19842e5c85f6aa46e3b096e615d0adb37c828
}
