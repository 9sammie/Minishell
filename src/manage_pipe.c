#include "../header/minishell.h"

//termine le node actuel
//crée un nouveau node
//met a jour le input et le output suivant (pipe)
int    manage_pipe(char *prompt_line, int *i, t_boolean *booleans, t_data *data, int *word_length)
{
    t_data  *last;
    t_cmds  *next_cmd;
    if (booleans->simple_quote || booleans->double_quote)
        return (ALL_OK);
    /*save word*/
    last = ft_lstlast(data);
    last->ls_io.io[1] = ft_strdup("pipe");
    if (last->ls_io.io[1])
    {
        /*fail*/
        return (ERR_PIPE);
    }
    next_cmd = malloc(sizeof(t_cmds));
    if (!next_cmd)
    {
        /*fail*/
        return (ERR_PIPE);
    }
    ft_lstadd_back(&last, next_cmd);
    next_cmd->io.io[0] = ft_strdup("pipe");
    if (last->ls_io.io[0])
    {
        /*fail*/
        return (ERR_PIPE);
    }
    word_length--;
    return (ALL_OK);
}
