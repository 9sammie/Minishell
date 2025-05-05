#include "../header/minishell.h"

static int  env_init(t_env **ls_env, char **env)
{
	unsigned int	i;
	t_env			*new_node;	

	i = 0;
	while (env[i])
	{
		new_node = malloc(sizeof(t_env));
		if (!new_node)
			return (0);
		new_node->env_line = ft_strdup(env[i]);
		if (!new_node->env_line)
			return (0);
		new_node->next = NULL;
		ft_lstadd_back((t_list**)ls_env, (t_list*)new_node);
		new_node = new_node->next;
		i++;
	}
	return (1);
} 

int data_init(t_data *data, char **env)
{
	data->ls_cmds = malloc(sizeof(t_cmds));
	if (!data->ls_cmds)
		return (0);
	data->ls_cmds->s_token_cmds = NULL;
	data->ls_cmds->next = NULL;
	data->ls_env = NULL;
	if (env_init(&data->ls_env, env) == 0)
		return (0);
	data->ls_io = malloc(sizeof(t_io));
	if (!data->ls_io)
		return (0);
	data->ls_io->io[0] = NULL;
	data->ls_io->io[1] = NULL;
	data->ls_io->rafters[0] = NO_RAFTERS;
	data->ls_io->rafters[1] = NO_RAFTERS;
	data->ls_io->pipe_input = false;
	data->ls_io->pipe_output = false;
	data->ls_io->next = NULL;
	return (1);
}

void    booleans_init(t_is_active *booleans)
{
	booleans->dollar = false;
	booleans->double_left_rafter = false;
	booleans->double_right_rafter = false;
	booleans->simple_left_rafter = false;
	booleans->simple_right_rafter = false;
	booleans->double_quote = false;
	booleans->simple_quote = false;
}

void    init_back_bool(t_is_active *booleans)
{
	booleans->dollar = false;
	booleans->double_left_rafter = false;
	booleans->double_right_rafter = false;
	booleans->simple_left_rafter = false;
	booleans->simple_right_rafter = false;
}
