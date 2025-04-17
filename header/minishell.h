#ifndef MINISHELL_H
	#define MINISHELL_H


#include <stdio.h> //printf, readline, perror
#include <readline/readline.h> //readline, rl_*
#include <readline/history.h> //readline, rl_*
#include <stdlib.h> //malloc, free, exit, ttyslot, getenv
#include <unistd.h> //write, access, read, close, fork, getcwd, chdir, *stat, unlink, execve, dup*, pipe, isatty, ttyname, ttyslot, tcsetattr, tcgetattr
#include <sys/types.h> //open, wait*, kill, *stat, opendir, closedir
#include <sys/stat.h> //open, stat
#include <fcntl.h> //open
#include <sys/wait.h> //wait*
#include <signal.h> //signal, kill
#include <dirent.h> //*dir
#include <string.h> //strerror
#include <errno.h> //perror
#include <sys/ioctl.h> //ioctl
#include <termios.h> //tcsetattr, tcgetattr
#include <curses.h> //tgetent, tgetflag, tgetnum,tgetstr, tgoto, tputs
#include <term.h> //getent, tgetflag, tgetnum, tgetstr, tgoto, tputs

#include "../libft/libft.h" 
#include "../src/pipex/header/pipex.h"


typedef enum e_error
{
	ALL_OK,
	ERR_CREAT,
	ERR_ID,
	ERR_EXEC,
    ERR_PIPE
}	t_error;

typedef struct s_io
{
    char    io[2];
    void    *next;
}           t_io;

typedef struct s_cmds
{
    int     index;
    char    **cmds;
    t_io    io;
    void    *next;
}           t_cmds;

typedef struct s_env
{
    char    *env_line;
    void    *next;
}           t_env;

typedef struct  s_data
{
    t_cmds  ls_cmds;
    t_io    ls_io;
    t_env   ls_env;
}           t_data;

typedef struct s_boolean
{
    bool    simple_quote;
    bool    double_quote;
    bool    simple_rafter;
    bool    double_rafter;
    bool    dollar;
}           t_boolean;

/*parsing.c*/
void parsing(char *prompt_line, t_data *data);
/*execution*/
int execution(char **commands, t_data *data);
/*manage_pipe*/
void    manage_pipe(char *prompt_line, t_boolean *booleans, t_data *data);
/*manage_dollar.c*/
int manage_dollar(char *prompt_line, t_boolean *booleans, t_data *data, int *i);
#endif
