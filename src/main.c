#include "../header/minishell.h"

int main(int ac, char **av, char **env)
{
	char     *prompt_line; //la ligne de prompt a recuperer si le signal est enter

    t_data  data; // contient toutes les struct
    // t_data  data_start; // sauvegarde le point de depart

    (void)ac;
    (void)av;
    data_init(&data, env);
    // ft_print_env(&data);
	while (1) // boucle qui maintient le programme ouvert
	{
        prompt_line = readline("minishell > "); //recupere la ligne dans le prompt
		if (prompt_line /*l'utilisateur a ecrit quelque chose*/)
		{
            add_history(prompt_line);
            parsing(prompt_line, &data);
			if (!data.ls_cmds->s_token_cmds) 
			{
				/*fail (et exit proprement ?)*/
                // free_all(prompt_line);
				return (ERR_CREAT); 
			}
            ft_print_tab(&data);
            // data = data_start;
            // if (execution(&data) == -1)
            // {
            //     /*fail (et exit proprement ?)*/
            //     // free_all(prompt_line);
            //     return (ERR_EXEC);
            // }
		}
	}
    ft_print_tab(&data);
	return (0);
}
