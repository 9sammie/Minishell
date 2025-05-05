#include "../../header/minishell.h"

static int create_new_node_cmd(t_cmds *ls_cmds)
{
	t_cmds *new_cmds;

	new_cmds = malloc(sizeof(t_cmds));
	if (!new_cmds)
		return (0);
	ft_lstadd_back((t_list**)&ls_cmds, (t_list*)new_cmds);
	ls_cmds = (t_cmds*)ft_lstlast((t_list*)ls_cmds);
	return (1);
}

//termine le node actuel
//crée un nouveau node
//met a jour le input et le output suivant (pipe)
int    manage_pipe(char *prompt_line, int *i, t_is_active *booleans, t_data *data, int *word_length)
{
	t_io *next_io;

	if (booleans->simple_quote || booleans->double_quote)
		return (1);
	(void)prompt_line;
	(void)i;
	if (!ft_isspace(prompt_line[*i - 1]))
		save_word(word_length, prompt_line, i, data, booleans);
	if (!data->ls_io->io[1])
		data->ls_io->pipe_output = true;
	next_io = malloc(sizeof(t_io));
	if (!next_io)
		return (0);
	data->ls_io->next = next_io;
	data->ls_cmds->io = next_io;
	data->ls_io = data->ls_io->next; //passage au node suivant
	data->ls_io->pipe_input = true; //input du nouveau node
	if (!create_new_node_cmd(data->ls_cmds)) //nous fait passer au node cmd suivant
		return (0);
	*word_length = 0; // pas sur
	return (1);
}
