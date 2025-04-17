#include "../header/minishell.h"

int execution(char **commands, char **io_put);
{
    /*en gros un pipex*/
}
// void    data_init(t_data *data)
// {
//     t_cmds   cmds; // chaque éléments de la ligne regroupés par séries de cmd simples
//     t_io     io; // tableau avec le in, le out si redirection (pipe, infile outfile)
//     t_env    env; //recuperer l'env

//     data->cmds = cmds;
//     data->env = env;
//     data->io = io;
// }

static void data_init(t_data *data)
{
    data->ls_cmds.cmds = NULL;
    data->ls_cmds.index = 0;
    data->ls_cmds.next = NULL;
    data->ls_env.env_line = NULL;
    data->ls_env.next = 0;
    data->ls_io.index = 0;
    data->ls_io.next = NULL;
}

int main(void)
{
	char     *prompt_line; //la ligne de prompt a recuperer si le signal est enter

    t_data  data; // contient toutes les struct

    data_init(&data);
	while (1) // boucle qui maintient le programme ouvert
	{
        prompt_line = readline("minishell > "); //recupere la ligne dans le prompt
		if (prompt_line /*l'utilisateur a ecrit quelque chose*/)
		{
            add_history(prompt_line);
            parsing(prompte_line, &data);
			if (!tokens) 
			{
				/*fail (et exit proprement ?)*/
                free_all(prompt_line);
				return (ERR_CREAT);
			}
            execution(prompt_line, io_put);
		}
	}
	return (0);
}
