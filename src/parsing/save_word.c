#include "../../header/minishell.h"

//enregistrer le mot qu'on vient de lire et passer au mot suivant dans le char **cmds
// on lui envoie l'index et la taille du mot
// il supprime les operateurs superflus // fait en amont (pas tous)
//il remplace les variable par le mot litteral// reinitialise les booleens et word_length
// check si le mot est un file ou une cmd/arg

static char	*substr_no_quotes(char *prompt_line, int start, int new_len, int len, char skip)
{ //LA LEN EST PAS TOUT A FAIT BONNE POUR PARCOURIR PROMPTLINE
	char	*result;
	size_t	i;

	i = 0;
	if (start > ft_strlen(prompt_line))
		len = 0;
	else if (len > (ft_strlen(prompt_line) - start))
		len = ft_strlen(prompt_line) - start;
	result = malloc(new_len + 1);
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

void save_word_in_tab(char *new_word, t_data *data, t_boolean *booleans)
{
	t_token_cmds    new_token_cmd;

	/*SI C'EST UN FILE*/
	/*enregistrer si on doit effacer ou concatener*/
	if (booleans->double_left_rafter)
		data->ls_io->io[2] = ft_strdup("dl");
	else if (booleans->simple_left_rafter)
		data->ls_io->io[2] = ft_strdup("sl");
	if (booleans->double_right_rafter)
		data->ls_io->io[3] = ft_strdup("dr");
	else if (booleans->simple_right_rafter)
		data->ls_io->io[3] = ft_strdup("sr");
	/*enregistrer le file en input ou output*/
	if (data->ls_io->io[2])
		data->ls_io->io[0] = new_word;
	if (data->ls_io->io[3])
		data->ls_io->io[1] = new_word;
	/*SI C'EST PAS UN FILE*/
	if (!data->ls_io->io[2] && !data->ls_io->io[3])
	{
		new_token_cmd.token_cmd = new_word; 
		new_token_cmd.next = NULL; 
		ft_lstadd_back(&(data->ls_cmds->s_token_cmds), &new_token_cmd);
	}
}


char	*find_var_in_env(t_env *env, char *var, int var_len)
{
	while (env->next)
	{
		if (!ft_strncmp(env->env_line, var, var_len) && env->env_line[var_len + 1] == '=')
			return (env->env_line);
		env = env->next;
	}
	return (NULL);
}

char *replace_variable(char *new_word, t_data *data)
{
	char	*var;
	char	*result;
	char	*env_var;

	var = ft_strtrim(new_word, '$');
	if (!var)
		return (NULL); //fail malloc
	free(new_word);

	env_var = find_var_in_env(&data->ls_env, var, ft_strlen(var));
	if (!env_var)
		return (NULL); //si la variable existe pas c'est = NULL mais c'est pas un fail
	result = ft_cutstr(env_var, ft_stlren(var) + 1);
	if (!result)
		return (NULL); //fail malloc
	free(var);
	return (result);
}

int save_word(int *word_length, char *prompt_line, int *i, t_data *data, t_boolean *booleans)
{
	char    *new_word;
	int     index;
	char	skip;
	int     start;
	int		new_wl;

	new_wl = *word_length;
	skip = '\0';
	index = *i - *word_length;
	start = index;
	while (index <= *i)
	{
		if (prompt_line[index] == '\"' && !booleans->simple_quote)
		{
			if (!booleans->double_quote)
			booleans->double_quote = true;
			else
			booleans->double_quote = false;
			new_wl--;
			skip = '\"';
		}
		if (prompt_line[index] == '\'' && !booleans->double_quote)
		{
			if (!booleans->simple_quote)
			booleans->simple_quote = true;
			else
			booleans->simple_quote = false;
			new_wl--;
			skip = '\'';
		}
		if (prompt_line[index] == '\\' && (prompt_line[index + 1] == '\\' || prompt_line[index + 1] == skip))
			new_wl--; // CE CAS N'EST PAS A GERER. "echo hello\ wolrd" devrais renvoyer "hello\ world".
		index++;
	}
	new_word = substr_no_quotes(prompt_line, start, new_wl, word_length, skip);
	if (!new_word)
		return (0);
	if (booleans->dollar)
		new_word = replace_variable(new_word, data);
	/*enregistrer new_word dans la structure file ou cmd*/
	save_word_in_tab(new_word, data, booleans);
    init_back_bool(booleans);
	*word_length = 0; //Remettre word_len a 0 pour le prochain mot.
	return (0);
}
