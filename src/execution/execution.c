#include "../../header/minishell.h"

/*
Your shell must implement the following builtins:
◦ echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit with no options
*/

static int  exec_cmd(t_data *data)
{
	if (ft_strncmp(data->ls_cmds->s_token_cmds->token_cmd, "echo", 4))
		exec_echo(data);
	else if (ft_strncmp(data->ls_cmds->s_token_cmds->token_cmd, "cd", 2))
		exec_cd(data);
	else if (ft_strncmp(data->ls_cmds->s_token_cmds->token_cmd, "pwd", 3))
		exec_pwd(data);
	else if (ft_strncmp(data->ls_cmds->s_token_cmds->token_cmd, "export", 6))
		exec_export(data);
	else if (ft_strncmp(data->ls_cmds->s_token_cmds->token_cmd, "unset", 5))
		exec_unset(data);
	else if (ft_strncmp(data->ls_cmds->s_token_cmds->token_cmd, "env", 3))
		exec_env(data);
	else if (ft_strncmp(data->ls_cmds->s_token_cmds->token_cmd, "exit", 4))
		exec_exit(data);
	else
		exec_auto(data);
}

int execution(t_data *data)
{
	while (data->ls_cmds)
	{
		exec_cmd(data);
		data->ls_cmds = data->ls_cmds->next;
	}
}