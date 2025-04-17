#include "../header/minishell.h"

//si simple quote : RIEN, sinon chercher ' ' ou ' " ' suivant pour delimiter la $VAR
int manage_dollar(char *prompt_line, t_boolean *booleans, t_data *data, int *i)
{
    if (booleans->simple_quote)
        return ;
    booleans->dollar = true;
    while (prompt_line[*i])
    {
        if (is_space(prompt_line[*i]) || prompt_line[*i] == '\"' || prompt_line[*i] == '$')
            break ;
        (*i)++;
    }
    /*remplacer le mot lu par la $var associée ou NULL si inexistante*/
    return (ALL_OK);
}