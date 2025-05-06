#include "../../header/minishell.h"

static int create_new_node_cmd(t_cmds **ls_cmds)
{
	t_cmds *new_cmds;

	new_cmds = malloc(sizeof(t_cmds)); //check fail
	new_cmds->s_token_cmds->token_cmd = NULL;
	new_cmds->s_token_cmds->next = NULL;
    new_cmds->next = NULL;
	ft_lstadd_back((t_list**)ls_cmds, (t_list*)new_cmds);
	return (0);
}

//termine le node actuel
//crée un nouveau node
//met a jour le input et le output suivant (pipe)
int    manage_pipe(char *prompt_line, int *i, t_is_active *booleans, t_data *data, int *word_length)
{
	if (booleans->simple_quote || booleans->double_quote)
		return (ALL_OK);
	(void)prompt_line;
	(void)i;
	if (prompt_line[*i - 1] != ' ')
	{
		printf("hello\n");
		save_word(word_length, prompt_line, i, data, booleans);
	}
	if (!data->ls_io->io[1])
	{
		data->ls_io->io[1] = ft_strdup("pipe"); //output de l'ancien node
		if (!data->ls_io->io[1])
		{
			/*fail*/
			return (ERR_PIPE);
		}
	}
	t_io *next_io;
	next_io = malloc(sizeof(t_io)); //check fail
	data->ls_io->next = next_io;
	data->ls_io = data->ls_io->next; //passage au node suivant
	data->ls_io->io[0] = ft_strdup("pipe"); //input du nouveau node
	if (!data->ls_io->io[0])
	{
		/*fail*/
		return (ERR_PIPE);
	}
	create_new_node_cmd(&data->ls_cmds); //nous fait passer au node cmd suivant
	// data->ls_cmds = data->ls_cmds->next;
	printf("\n%s\n\n", data->ls_cmds->s_token_cmds->token_cmd);
	/*A FAIRE associer le node cmd au node io*/
	*word_length = 0; // pas sur
	return (ALL_OK);
}
