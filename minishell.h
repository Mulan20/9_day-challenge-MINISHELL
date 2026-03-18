#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//types of token
typedef enum e_token_type
{
    WORD,
    PIPE,
    REDIR_IN, 
    REDIR_OUT, 
    APPEND
}   t_token_type; 

//each token would value value type and next token 
typedef struct s_token
{
    char    *value;
    t_token_type    type;
    struct s_token  *next;
}   t_token;

//input.c 
void    *ft_memcpy(void *dest, void *src, size_t n);
int ft_strlen(char *s);
char    *get_user_input(void); 

//lexer.c
t_token    *define_token(char *input);
void print_tokens(t_token *tokens);
void    add_token(t_token **list, t_token *new); 
void    add_token(t_token **list, t_token *new); 

#endif
