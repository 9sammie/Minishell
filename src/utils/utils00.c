#include "../../header/minishell.h"

char	*ft_cutstr(char const *s, unsigned int start)
{
	char	*result;
	size_t	i;
	int		len;

	i = 0;
	len = ft_strlen(s) - start;
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

void	ft_envadd_back(t_env **lst, t_list *new)
{
	t_env	*current;

	if (!lst)
		return ;
	current = ft_lstlast(*lst);
	if (current)
		current->next = new;
	else
		*lst = new;
}