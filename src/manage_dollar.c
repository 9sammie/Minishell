#include "../header/minishell.h"

//si simple quote : RIEN, sinon chercher ' ' ou ' " ' suivant pour delimiter la $VAR
int manage_dollar(char *prompt_line, t_boolean *booleans, t_data *data, int *i, int *word_length)
{
	if (booleans->simple_quote == true)
		return (ALL_OK);
	if (*word_length && prompt_line[*i - 1] != '$')//save le mot precedent
		save_word(word_length, prompt_line, i, data, &booleans); 
	booleans->dollar = true;
	if (prompt_line[*i - 1] == '$') //cas particulier ! $$
		save_word(word_length, prompt_line, i + 1, data, &booleans); 
	return (ALL_OK);
}



/*CETTE PARTIE SERA A METTRE DANS SAVEWORD*/
// while (prompt_line[*i])
// {
//     if (is_space(prompt_line[*i]) || prompt_line[*i] == '\"')
//         break ;
//     if (prompt_line[*i] == '$')
//     {

//     }
//     (*i)++;
// }
// /*remplacer le mot lu par la $var associée ou NULL si inexistante*/