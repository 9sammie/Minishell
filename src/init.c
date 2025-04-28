#include "../header/minishell.h"

static int  env_init(t_env *ls_env, char **env)
{
	unsigned int	i;
	t_env			*new_line_env;	

    new_line_env = malloc(sizeof(t_env)); //check fail
    new_line_env->next = NULL;
	i = 0;
	while (env[i])
	{
        printf("1) %s\n", env[i]);
		new_line_env->env_line = ft_strdup(env[i]);
		if (!new_line_env->env_line)
			return (0);
        printf("2) %s\n", env[i]);
		ft_lstadd_back((t_list**)&ls_env, (t_list*)new_line_env);
		i++;
	}
	return (1);
} 

void data_init(t_data *data, char **env)
{
    
    data->ls_cmds = malloc(sizeof(t_cmds)); //check fail
    data->ls_cmds->s_token_cmds = NULL;
	data->ls_cmds->index = 0;
	data->ls_cmds->next = NULL;
    data->ls_env = malloc(sizeof(t_env)); //check fail
	env_init(data->ls_env, env);
    data->ls_io = malloc(sizeof(t_io)); //check fail
    
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