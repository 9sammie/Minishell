#include "../../header/minishell.h"

int    manage_simple_quote(char *promptline, int *i, t_is_active *booleans, t_data *data, int *word_length)
{
	if (booleans->double_quote == 1) // on se trouve deja dans une double quote
		return ALL_OK;
	if (booleans->simple_quote == 1 && promptline[*i - 1] != '\\') // si on est deja dans la quote
		booleans->simple_quote = 0; // on sort
	else if (booleans->simple_quote == 0) // si on est pas dans la quote
		booleans->simple_quote = 1; // on rentre
	if (booleans->dollar == 1)
		save_word(*word_length, promptline, i, data, booleans);
	return (ALL_OK);
}

int    manage_double_quote(char *promptline, int *i, t_is_active *booleans, t_data *data, int *word_length)
{
	if (booleans->simple_quote == 1) // on se trouve deja dans une double quote
		return ALL_OK;
	if (booleans->double_quote == 1 && promptline[*i - 1] != '\\') // si on est deja dans la quote
        booleans->simple_quote = 0; // on sort
	else if (booleans->double_quote == 0)// si on est pas dans la quote
		booleans->double_quote = 1;// on rentre
	if (booleans->dollar == 1)
		save_word(*word_length, promptline, i, data, booleans);
	return (ALL_OK);
}