#include "../header/minishell.h"

int    clean_tab(t_cmds *ls_cmd_head)
{
    t_cmds  *current;

    current = ls_cmd_head;
    while (current)
    {
        while (current->s_token_cmds)
        {
            free(current->s_token_cmds->token_cmd);
            current->s_token_cmds = current->s_token_cmds->next;
        }
        free(current->io);
        current = current->next;
    }
    return (ALL_OK);
}

int main(int ac, char **av, char **env)
{
	char    *prompt_line;
	t_data  *data;
	t_data  *data_head;
    t_cmds  *ls_cmd_head;

	(void)ac;
	(void)av;
	data = malloc(sizeof(t_data));
	if (!data)
		return(ALL_OK);
    if (!data_init(data, env))
		return (clean_tab(ls_cmd_head));
    data_head = data;
    ls_cmd_head = data->ls_cmds;
	while (1)
	{
		prompt_line = readline("minishell > ");
		if (prompt_line)
		{
			add_history(prompt_line);
			parsing(prompt_line, data);
			if (!data->ls_cmds->s_token_cmds) 
				return (free_all(data_head));
			ft_print_tab(ls_cmd_head);
			// if (execution(&data) == -1)
			// {
			//     /*fail (et exit proprement ?)*/
			//     // free_all(prompt_line);
			//     return (ERR_EXEC);
			// }
            // clean_tab(ls_cmd_head); //reset la data pour la cmd suivante
		}
	}
	return (ALL_OK);
}
