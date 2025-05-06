#include "../../header/minishell.h"

char	*ft_cutstr(char const *s, unsigned int start)
{
	char	*result;
	int	    i;
	int		len;

	i = 0;
	len = (int)ft_strlen(s) - start;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int free_all(t_data *data)
{
    (void)data;
    return (0);
}


void    ft_print_env(t_data *data)
{
    int i;

	i = 1;
	printf("env tab :\n\n");
	while (data->ls_env)
	{
		printf("%d) %s\n", i, data->ls_env->env_line);
		data->ls_env = data->ls_env->next; 
		i++;
	}
}

void	ft_print_tab(t_data *data)
{
	int i;
    t_data *current;

    current = data;
	printf("\ncmds tab :\n\n");
    int j = 1;
	while (current->ls_cmds != NULL)
	{
        i = 1;
		while (current->ls_cmds->s_token_cmds != NULL)
		{
			printf("node : %d, token : %d : %s\n", j, i,  current->ls_cmds->s_token_cmds->token_cmd);
			current->ls_cmds->s_token_cmds = current->ls_cmds->s_token_cmds->next;
            i++;
		}
        j++;
        printf("--------------------\n");
		current->ls_cmds = current->ls_cmds->next; 
	}
}
