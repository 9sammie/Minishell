#include "../header/minishell.h"

bool is_space(char c)
{
    if (c == ' ')
        return (true);
    if (c == '\t')
        return (true);
    if (c == '\n')
        return (true);
    if (c == '\v')
        return (true);
    if (c == '\f')
        return (true);
    if (c == '\r')
        return (true);
    return (false);
}