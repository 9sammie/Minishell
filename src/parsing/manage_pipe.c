#include "../../header/minishell.h"


static int create_new_node_cmd(t_data *data)
{
    t_cmds new_cmds;

    ft_lstadd_back(data->ls_cmds, &new_cmds);
}

//termine le node actuel
//crée un nouveau node
//met a jour le input et le output suivant (pipe)
int    manage_pipe(char *prompt_line, int *i, t_boolean *booleans, t_data *data, int *word_length)
{
    if (booleans->simple_quote || booleans->double_quote)
        return (ALL_OK);
    /*A FAIRE save word*/
    if (prompt_line[*i - 1] != ' ')
        save_word(&word_length, &prompt_line, &i, &data, &booleans);
    if (!data->ls_io->io[1])
    {
        data->ls_io->io[1] = ft_strdup("pipe"); //output de l'ancien node
        if (data->ls_io->io[1])
        {
            /*fail*/
            return (ERR_PIPE);
        }
    }
    data->ls_io = data->ls_io->next; //passage au node suivant
    data->ls_io->io[0] = ft_strdup("pipe"); //input du nouveau node
    if (data->ls_io->io[0])
    {
        /*fail*/
        return (ERR_PIPE);
    }
    create_new_node_cmd(data); //nous fait passer au node cmd suivant
    /*A FAIRE associer le node cmd au node io*/
    word_length--;
    return (ALL_OK);
}
