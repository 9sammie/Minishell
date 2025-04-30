#include "../../header/minishell.h"

char	*var_value(char *s, int start) //retourner 
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1 - start));
	while ()
	{
		
	}
}

int	var_len(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '=')
	{
		i++;
	}
	return (i);
}

int	exec_echo(t_data *data)
{
	//Check s'il faut un autre pointeur sur token.
	int		i;
	int		varlen;
	t_env	*variable;
	bool	option;

	variable = data->ls_env;
	if (data->ls_cmds->s_token_cmds->token_cmd == "-n") // verifier si option ou non.
		option = 1;
	i = 0;
	while (data->ls_cmds->s_token_cmds->token_cmd) //Print toute les *str.
	{
		if (data->ls_cmds->s_token_cmds->token_cmd[i] == '$') //on cherche la variable dans env.
		{
			varlen = var_len(data->ls_cmds->s_token_cmds->token_cmd);
			if (ft_strncmp(variable, data->ls_cmds->s_token_cmds->token_cmd, var_len))
				printf("%s ", var_value(data->ls_cmds->s_token_cmds->token_cmd, varlen));
		}
		else
			printf("%s ", data->ls_cmds->s_token_cmds->token_cmd);
		data->ls_cmds->s_token_cmds = data->ls_cmds->s_token_cmds->next;
	}
	if (option = 0)
		printf("\n");
}
