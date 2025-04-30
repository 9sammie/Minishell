#include "../header/minishell.h"

static int  env_init(t_env **ls_env, char **env)
{
	unsigned int	i;
	t_env			*new_node;	

    // new_line_env = ls_env;
    // new_line_env->env_line = ls_env->env_line;
    // new_line_env->next = NULL;
	i = 0;
	while (env[i]) //env[i]
	{
        new_node = malloc(sizeof(t_env)); //check fail
		new_node->env_line = ft_strdup(env[i]);
		if (!new_node->env_line)
			return (0);
        new_node->next = NULL;
		ft_lstadd_back((t_list**)ls_env, (t_list*)new_node);
        new_node = new_node->next;
        i++;
	}
    // new_node->next = NULL;
	return (1);
} 

void data_init(t_data *data, char **env)
{
    
    data->ls_cmds = malloc(sizeof(t_cmds)); //check fail
    data->ls_cmds->s_token_cmds = NULL;
	data->ls_cmds->index = 0;
	data->ls_cmds->next = NULL;
    data->ls_env = NULL;//malloc(sizeof(t_env)); //check fail
	env_init(&data->ls_env, env);
    // printf("ENVLINE : %s\n", data->ls_env->env_line);
    data->ls_io = malloc(sizeof(t_io)); //check fail
    data->ls_io->io[0] = NULL;
    data->ls_io->io[1] = NULL;
    data->ls_io->io[2] = NULL;
    data->ls_io->io[3] = NULL;
	data->ls_io->next = NULL;
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