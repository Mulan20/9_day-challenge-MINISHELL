#include "../include/minishell.h"

void    *ft_memcpy(void *dest, void *src, size_t n)
{
    size_t  i;

    if (!dest || !src)
        return NULL;
    i = 0; 
    while (i < n)
    {
       ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return dest; 
}

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}
char *get_user_input(void)
{
       char buffer[64];
       char *line = NULL;
       char *tmp;
       ssize_t bytes;
       ssize_t len = 0;

       while ((bytes = read(0, buffer, sizeof(buffer))) > 0)
       {
            buffer[bytes] = '\0';
            tmp = realloc(line, len + bytes + 1);
            if (!tmp)
            {
                free(line);
                return NULL;
            }
            line = tmp;

            ft_memcpy(line + len, buffer, bytes);
            len += bytes;
            line[len] = '\0';
            if (line[len - 1] == '\n')
                break;
       }

       if (bytes <= 0 && len == 0)
        return (free(line), NULL);
       if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
       return (line); 
}
