#include "../../header/minishell.h"

void	*print_var_value(t_env *ls_env, char *s, int start) //retourner la valeur correspondant à une variable
{
	int		i;
	char	*str;
	t_env	*variable; //pointeur sur le tab env pour ne pas deplacer le pointeur de base
	int		value_len;

	i = 0;
	variable = ls_env;
	while (variable->env_line)
	{
		if (ft_strncmp(s, variable->env_line, (start)))
		{
			value_len = ft_strlen(variable->env_line) + 1 - start;
			str = malloc(sizeof(char) * (value_len));
			str = ft_substr(variable->env_line, start, value_len);
			printf("%s ", str);
			free(str);
		}
		variable = variable->next; //si on ne trouve rien, la fonction continue normalement
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
	i++; //pour le '='
	return (i);
}

int	exec_echo(t_data *data)
{
	int		i;
	int		varlen;
	bool	option;

	if (data->ls_cmds->s_token_cmds->token_cmd == "-n") // verifier si option ou non.
		option = 1;
	i = 0;
	while (data->ls_cmds->s_token_cmds->token_cmd) //Print toute les *str.
	{
		if (data->ls_cmds->s_token_cmds->token_cmd[i] == '$') //on cherche la variable dans env.
		{
			varlen = var_len(data->ls_cmds->s_token_cmds->token_cmd);
			print_var_value(data->ls_env, data->ls_cmds->s_token_cmds->token_cmd, varlen);
		}
		else
			printf("%s ", data->ls_cmds->s_token_cmds->token_cmd);
		data->ls_cmds->s_token_cmds = data->ls_cmds->s_token_cmds->next;
	}
	if (option = 0)
		printf("\n");
}
