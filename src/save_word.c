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
	while (i < len && (start + i < ft_strlen(prompt_line))) // a optimiser
	{
		if (prompt_line[start + i] == '\\' && (prompt_line[start + i + 1] == skip || prompt_line[start + i + 1] == '\\'))
		{ // si on tombe sur un \, alors on check si le suivant est une quote ou un autre \. sinon on s'en fiche
			i++;
			result[i] = prompt_line[start + i];
		}
		else if (prompt_line[start + i] != skip)
			result[i] = prompt_line[start + i]; //si on s'en fiche on ecrit le char normal
		i++;
	}
	result[i] = '\0';
	return (result);
}

int save_word_in_tab(char *new_word, t_data *data, t_boolean *booleans)
{
	if (booleans->double_left_rafter)
		data->ls_io.io[2] = ft_strdup("dl");
	else if (booleans->simple_left_rafter)
		data->ls_io.io[2] = ft_strdup("sl");
	if (booleans->double_right_rafter)
		data->ls_io.io[3] = ft_strdup("dr");
	else if (booleans->simple_right_rafter)
		data->ls_io.io[3] = ft_strdup("sr");

	if (data->ls_io.io[2])
		data->ls_io.io[0] = new_word;
	if (data->ls_io.io[3])
		data->ls_io.io[1] = new_word;
}

int save_word(int *word_length, char *prompt_line, int *i, t_data *data, t_boolean *booleans)
{
	char    *new_word;
	int     index;
	char	skip;
	int     start;

	if (booleans->dollar)
		save_variable();
	skip = '\0';
	index = i - word_length;
	start = index;
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
		if (prompt_line[index] == '\\' && (prompt_line[index + 1] == '\\' || prompt_line[index + 1] == skip))
			word_length--;
		index++;
	}
	new_word = substr_no_quotes(prompt_line, start, word_length, skip);
	if (!new_word)
		return (0);
	/*enregistrer new_word dans la structure file ou cmd*/
	if (save_word_in_tab(new_word, data, booleans))
		return (0)
}
