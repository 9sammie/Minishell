#include "../header/minishell.h"

void    identify_simple_cmds(char *prompt_line, t_data *data)
{
    int         word_length;
    t_boolean   booleans;
    int         i;
    
    booleans_init(booleans);
    i = 0;
    word_length = 0;
    while (prompt_line[i])
    {
        if (prompt_line[i] == '\'')
            manage_single_quote(prompt_line, &i, booleans);
            // boolen = true ou false
        if (prompt_line[i] == '\"')
            manage_double_quote(prompt_line, &i, booleans);
            // boolen = true ou false
        if (prompt_line[i] == '|') 
            manage_pipe(prompt_line, &i); 
            //termine le node actuel, crée un nouveau node, met a jour le input et le output suivant (pipe)
        if (prompt_line[i] == '>')
            manage_right_rafter(prompt_line, &i, booleans);
            //bool pour savoir si c'est > ou >> SINON error syntax. chercher ' ' ou ' " ' suivant pour delimiter le fd outfile
        if (prompt_line[i] == '<')
            manage_left_rafter(prompt_line, &i, booleans);
            //bool pour savoir si c'est > ou >> SINON error syntax. chercher ' ' ou ' " ' suivant pour delimiter le fd infile
        if (prompt_line[i] == '$')
            manage_dollar(prompt_line, &i, booleans); 
            //si simple quote : RIEN, sinon chercher ' ' ou ' " ' suivant pour delimiter la $VAR
        if (is_space(prompt_line[i]))
            save_word(word_length, prompt_line, i, data);
            //enregistrer le mot qu'on vient de lire et passer au mot suivant dans le char **cmds
        word_length++;
        i++;
    }
}
t_cmds parsing(char *prompt_line, t_data *data)
{
	char    ***tokens;
	char    **simple_cmd;
	/*separer tokens en les words des operators*/
	identify_simple_cmds(prompt_line, data);
	/*separer les words en arguments des cmd*/
	identify_words();
	/*stocker les $VAR*/
	stock_var();
	/*remplacer les $VAR, (alias et wildcards) par ce qu'ils veulent litteralement dire*/
	replace_var();
}