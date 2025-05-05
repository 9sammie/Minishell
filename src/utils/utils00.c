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
		// printf("%d) io : %s %s, cmds :", i, data->ls_cmds->io->io[0], data->ls_cmds->io->io[1]);
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
	printf("\nio tab :\n\n");
	i = 1;
	while (current->ls_io != NULL)
	{
		printf("%d) input %s output %s nature i %s nature o %s\n\n", i, current->ls_io->io[0], data->ls_io->io[1], data->ls_io->io[2], data->ls_io->io[3]);
		current->ls_io = current->ls_io->next; 
		i++;
	}
}
