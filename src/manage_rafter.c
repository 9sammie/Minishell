
#include "../header/minishell.h"

void	manage_right_rafter(char *prompt_line, t_is_active *is_active)
{
	if (is_active->simple_rafter == 0)
		is_active->simple_rafter = 1;
	if (is_active->simple_rafter == 1)
		is_active->simple_rafter = 2;
	if (is_active->simple_rafter == 2)
		;//fail ERR_RAFTER (syntaxe error);
}

void	manage_left_rafter(char *prompt_line, t_is_active *is_active)
{
	if (is_active->double_rafter == 0)
		is_active->double_rafter = 1;
	if (is_active->double_rafter == 1)
		is_active->double_rafter = 2;
	if (is_active->double_rafter == 2)
		;//fail ERR_RAFTER (syntaxe error);
}
