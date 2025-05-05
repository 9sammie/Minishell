#include "../header/minishell.h"

int main(int ac, char **av, char **env)
{
	char    *prompt_line;
	t_data  *data;
	t_data  *data_head;

	(void)ac;
	(void)av;
	data = malloc(sizeof(t_data));
	if (!data)
		return(ALL_OK);
	data_head = data;
	if (!data_init(data, env))
		return (free_all(data_head));
	while (1)
	{
		prompt_line = readline("minishell > ");
		if (prompt_line)
		{
			add_history(prompt_line);
			parsing(prompt_line, data);
			if (!data->ls_cmds->s_token_cmds) 
				return (free_all(data_head));
			printf("(main)mot actuel rangé : %s\n", data->ls_cmds->s_token_cmds->token_cmd);
			ft_print_tab(data_head);
			// data = data_start;
			// if (execution(&data) == -1)
			// {
			//     /*fail (et exit proprement ?)*/
			//     // free_all(prompt_line);
			//     return (ERR_EXEC);
			// }
		}
	}
	ft_print_tab(data_head);
	return (ALL_OK);
}
