#include "../include/minishell.h"

//the following is just printing out not creating a token 
// void    define_token(char *input)
// {
//     int i = 0; //counter
//     int j; 
//     while (input[i])
//     {
//         while (input[i] == ' ')
//             i++;
//         if (!input[i])
//             break;
//         if (input[i] == '|')
//         {
//             write(1, "PIPE", 4);
           
//         }
//         else if (input[i] == '>')
//         {
//             if (input[i + 1] == '>')
//             {
//                 write(1, "APPEND", 6);
//                 i++;
//             }
//             else
//             {
//                  write(1, "REDIR_OUT", 9);
//             }
//         }
//         else if (input[i] == '<')
//         {
//             write(1, "REDIR_IN", 8);
//         }
//         else
//         {
//             write(2, "WORD: ", 6);
//             j = 0;
//             while ( input[i + j] && input[i + j] != ' ' && input[i + j] != '|' && input[i + j] != '<' && input[i + j] != '>')
//            {
//                 write(1, &input[i + j], 1);
//                 j++;
//             }
            
//             i += j - 1; 
//         }
//         write(1, "\n", 1);
//         i++;
//     }
// }

char    *ft_substr(char *s, int start, int len)
{
    char *res;
    int i;
    res = malloc(len + 1);
    if (!res)
        return NULL; 
    i = 0; 
    while ( i < len)
    {
        res[i] = s[start + i];
        i++;
    }
    res[i] = '\0';
    return res; 
}

void    skip_spaces(char *input, int *i)
{
    while (input[*i] == ' ')
        (*i)++;
}

int is_operator(char c)
{
    return (c == '|' || c == '<' || c == '>');
}
t_token *create_token(t_token_type type, char *value)
{
    t_token *new; 

    new = malloc(sizeof(t_token));
    if (!new)
        return NULL;
    new->type = type;
    new->value = value;
    new->next = NULL; 

    return (new);
}

void    add_token(t_token **list, t_token *new)
{
    t_token *temp;

    if (!list)
    {
        *list = new;
        return ; 
    }

    temp = *list; 
    while (temp -> next)
        temp = temp -> next; 

    temp -> next = new; 
}

void print_tokens(t_token *tokens)
{
    while (tokens)
    {
        printf("TYPE: %d VALUUE: %s\n", tokens->type, tokens->value);
        tokens = tokens->next;
    }
}

t_token   *define_token(char *input)
{
    t_token *tokens = NULL;
    int i = 0;
    int start; 

    while (input[i])
    {
        skip_spaces(input, &i);
        if (!input[i])
            break;
        if (input[i] == '|')
            add_token(&tokens, create_token(PIPE, NULL));
        else if (input[i] == '>')
        {
            if (input[i + 1] == '>')
            {
                add_token(&tokens, create_token(APPEND, NULL));
                i++;
            }
            else  
                add_token(&tokens, create_token(REDIR_OUT, NULL));
        }
        else if (input[i] == '<')
            add_token(&tokens, create_token(REDIR_IN, NULL));
        else
        {
            start = i;
            while (input[i] && input[i] != ' ' && !is_operator(input[i]))
                i++;
            add_token(&tokens, create_token(WORD, ft_substr(input, start, i - start)));
            i--;
        }
        i++;
    }
    return tokens; 
}
