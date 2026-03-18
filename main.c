#include "../include/minishell.h"


int main (int ac, char **av)
{
    (void)ac;
    (void)av;
    char *input; 
    t_token *tokens; 
    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(1, "minishell$ ", 11);
        input = get_user_input(); 
        if (!input)
        {
            if (isatty(STDIN_FILENO))
                write(1, "exit\n", 5);
            break;
        }

        write(1, "Input:", 6);
        write(1, input, ft_strlen(input));
        write(1, "\n", 1);
        
        tokens = define_token(input);
        print_tokens(tokens);
        free(input);
    }
    return 0;
}
