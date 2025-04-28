#include "../../header/minishell.h"

static int  env_init(t_env *ls_env, char **env)
{
	unsigned int	i;
	t_env			new_line_env;	

	i = 0;
	while (env[i])
	{
		new_line_env.env_line = ft_strdup(env[i]);
		if (!new_line_env.env_line)
			return (0);
		ft_lstadd_back(&ls_env, &new_line_env);
		i++;
	}
	return (1);
} 

t_data data_init(t_data *data, char **env)
{
	data->ls_cmds->s_token_cmds = NULL;
	data->ls_cmds->index = 0;
	data->ls_cmds->next = NULL;
	env_init(&data->ls_env, env);

	data->ls_io->next = NULL;
    return (*data);
}

void    booleans_init(t_boolean *booleans)
{
	booleans->dollar = false;
	booleans->double_left_rafter = false;
	booleans->double_right_rafter = false;
	booleans->simple_left_rafter = false;
	booleans->simple_right_rafter = false;
	booleans->double_quote = false;
	booleans->simple_quote = false;
}

void    init_back_bool(t_boolean *booleans)
{
    booleans->dollar = false;
	booleans->double_left_rafter = false;
	booleans->double_right_rafter = false;
	booleans->simple_left_rafter = false;
	booleans->simple_right_rafter = false;
}