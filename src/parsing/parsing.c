#include "../../header/minishell.h"

void parsing(char *prompt_line, t_data *data)
{
    int         word_length;
    t_is_active   booleans;
    int         i;
    
    booleans_init(&booleans);
    i = 0;
    word_length = 0;
    while (prompt_line[i])
    {
        if (prompt_line[i] == '\'')
            manage_simple_quote(prompt_line, &i, &booleans, data, &word_length);
            // boolen = true ou false 
        if (prompt_line[i] == '\"')
            manage_double_quote(prompt_line, &i, &booleans, data, &word_length);
            // boolen = true ou false
        if (prompt_line[i] == '|') 
            manage_pipe(prompt_line, &i, &booleans, data, &word_length); 
            //termine le node actuel, crée un nouveau node, met a jour le input et le output suivant (pipe)
        if (prompt_line[i] == '>')
            manage_right_rafter(prompt_line, &i, &booleans, data, &word_length);
            //bool pour savoir si c'est > ou >> SINON error syntax. chercher ' ' ou ' " ' suivant pour delimiter le fd outfile
        if (prompt_line[i] == '<')
            manage_left_rafter(prompt_line, &i, &booleans, data, &word_length);
            //bool pour savoir si c'est > ou >> SINON error syntax. chercher ' ' ou ' " ' suivant pour delimiter le fd infile
        if (prompt_line[i] == '$')
            manage_dollar(prompt_line, &booleans, data, &i, &word_length); 
            //si simple quote : RIEN, sinon chercher ' ' ou ' " ' suivant pour delimiter la $VAR
        if (ft_isspace(prompt_line[i]) && !booleans.simple_quote && !booleans.double_quote)
            save_word(&word_length, prompt_line, &i, data, &booleans);
            //enregistrer le mot qu'on vient de lire et passer au mot suivant dans le char **cmds
        else
            word_length++;
        i++;
    }
    save_word(&word_length, prompt_line, &i, data, &booleans); //save le dernier mot
}
