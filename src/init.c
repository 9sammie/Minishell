#include "../header/minishell.h"

void data_init(t_data *data)
{
    data->ls_cmds.cmds = NULL;
    data->ls_cmds.index = 0;
    data->ls_cmds.next = NULL;
    data->ls_env.env_line = NULL;
    data->ls_env.next = 0;
    data->ls_io.next = NULL;
}

void    booleans_init(booleans)
{

}
