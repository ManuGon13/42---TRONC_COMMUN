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
}
