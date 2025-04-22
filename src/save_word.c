#include "../header/minishell.h"

//enregistrer le mot qu'on vient de lire et passer au mot suivant dans le char **cmds
// on lui envoie l'index et la taille du mot
// il supprime les operateurs superflus // fait en amont (pas tous)
//il remplace les variable par le mot litteral// reinitialise les booleens et word_length
// check si le mot est un file ou une cmd/arg

static char	*substr_no_quotes(char *prompt_line, int start, int len, char skip)
{
	char	*result;
	size_t	i;

	i = 0;
	if (start > ft_strlen(prompt_line))
		len = 0;
	else if (len > (ft_strlen(prompt_line) - start))
		len = ft_strlen(prompt_line) - start;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len && (start + i < ft_strlen(prompt_line)))
	{
        if (prompt_line[start + i] == '\\')
            /*fonctionnement similaire a printf*/
            
		// if (prompt_line[start + i] != skip)
		// 	result[i] = prompt_line[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int save_word(int *word_length, char *prompt_line, int *i, t_data *data, t_boolean *booleans)
{
	char    *new_word;
	int     index;
	char	skip;

	if (booleans->dollar)
	    save_variable();
	skip = '\0';
	index = i - word_length;
	while (index <= i)
	{
		if (prompt_line[index] == '\"' && !booleans->double_quote && !booleans->simple_quote)
		{
			word_length -= 2;
			skip = '\"';
		}
		if (prompt_line[index] == '\'' && !booleans->double_quote && !booleans->simple_quote)
		{
			word_length -= 2;
			skip = '\'';
		}
        if (prompt_line[index] == '\\' && (prompt_line[index + 1] == '\'' || prompt_line[index + 1] == '\"' || prompt_line[index + 1] == '\\'))
            word_length--;
		index++;
	}
	new_word = substr_no_quotes(prompt_line, i - word_length, word_length, skip);
	if (!new_word)
		return (ERR_MALLOC);
    /*enregistrer new_word dans la structure file ou cmd*/
}
