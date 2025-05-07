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

void	ft_print_tab(t_cmds *ls_cmd)
{
	int i;
    t_cmds *current;

    current = ls_cmd;
	printf("\ncmds tab :\n\n");
    int j = 1;
	while (current != NULL)
	{
        i = 1;
		while (current->s_token_cmds != NULL)
		{
			printf("node : %d, token : %d : %s\n", j, i,  current->s_token_cmds->token_cmd);
			current->s_token_cmds = current->s_token_cmds->next;
            i++;
		}
        j++;
        printf("--------------------\n");
		current = current->next; 
	}
}


void	ft_cmdadd_back(t_cmds **lst, t_cmds *new)
{
	t_cmds	*current;

	if (!lst)
		return ;
	current = ft_cmdlast(*lst);
	if (current)
		current->next = new;
	else
		*lst = new;
}

t_cmds	*ft_cmdlast(t_cmds *lst)
{
    t_cmds  *last;

	if (!lst)
		return (NULL);
    last = lst;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}