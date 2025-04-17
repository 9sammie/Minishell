#include "../header/minishell.h"

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
            parsing(prompt_line, &data);
			if (!data.ls_cmds.cmds) 
			{
				/*fail (et exit proprement ?)*/
                free_all(prompt_line);
				return (ERR_CREAT);
			}
            if (execution(prompt_line, &data) == -1)
            {
                /*fail (et exit proprement ?)*/
                free_all(prompt_line);
                return (ERR_EXEC);
            }
		}
	}
	return (0);
}
