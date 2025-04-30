#include "../../header/minishell.h"

int	exec_echo(t_data *data)
{
	//Check s'il faut un autre pointeur sur token.
	bool	option;

	if (data->ls_cmds->s_token_cmds->token_cmd == "-n") // verifier si option ou non.
		option = 1;
	while (data->ls_cmds->s_token_cmds->token_cmd) //Print toute les *str.
	{
		printf("%s ", data->ls_cmds->s_token_cmds->token_cmd);
		data->ls_cmds->s_token_cmds = data->ls_cmds->s_token_cmds->next;
	}
	if (option = 0)
		printf("\n");
}
