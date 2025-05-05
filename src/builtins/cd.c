#include "../../header/minishell.h"

void	exec_cd(t_data *data)
{
	//chdir
	t_cmds	*path_pointer;
	char	*path;
	int		i;

	path_pointer = data->ls_cmds; //S'assurer que ls_cmds passe au prochain node. Pour que PATH est le bon.
	path_pointer = path_pointer->next; //aller au bon node pour choper le chemin
	path = path_pointer->s_token_cmds; // récuperer le chemin
	i = 0;
	if (path[0] == '/') //chemin absolue
	{
	
	}
	if (path[0] == '.') //chemin relatif
	{

	}
}