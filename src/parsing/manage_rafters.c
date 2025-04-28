#include "../../header/minishell.h"

int manage_right_rafter(char *prompt_line, int *i, t_boolean *booleans, t_data *data, int *word_length)
{
	if (booleans->simple_quote || booleans->double_quote)
		return (ALL_OK);
	if (*word_length)//save le mot precedent
		save_word(word_length, prompt_line, i, data, &booleans);
	if (booleans->double_right_rafter = true) //troisieme chevron syntax error!
		return (ERR_RAFT);
	if (booleans->simple_right_rafter == false) // premier chevron
		booleans->simple_right_rafter = true;
	else if (booleans->simple_right_rafter == true) // deuxieme chevron
		booleans->double_right_rafter = true;
	word_length--;
	return (ALL_OK);
}

int manage_left_rafter(char *prompt_line, int *i, t_boolean *booleans, t_data *data, int *word_length)
{
	if (booleans->simple_quote || booleans->double_quote)
		return (ALL_OK);
	if (*word_length)//save le mot precedent
		save_word(word_length, prompt_line, i, data, &booleans);
	if (booleans->double_left_rafter = true) //troisieme chevron syntax error!
		return (ERR_RAFT);
	if (booleans->simple_left_rafter == false) // premier chevron
		booleans->simple_left_rafter = true;
	else if (booleans->simple_left_rafter == true) // deuxieme chevron
		booleans->double_left_rafter = true;
	word_length--;
	return (ALL_OK);
}
