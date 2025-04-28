#include "../../header/minishell.h"

//si simple quote : RIEN, sinon chercher ' ' ou ' " ' suivant pour delimiter la $VAR
int manage_dollar(char *prompt_line, t_is_active *booleans, t_data *data, int *i, int *word_length)
{
	if (booleans->simple_quote == true)
		return (ALL_OK);
	if (*word_length && prompt_line[*i - 1] != '$')//save le mot precedent
		save_word(word_length, prompt_line, i, data, booleans); 
	booleans->dollar = true;
	if (prompt_line[*i - 1] == '$') //cas particulier ! $$
		save_word(word_length, prompt_line, i + 1, data, booleans); 
	return (ALL_OK);
}
