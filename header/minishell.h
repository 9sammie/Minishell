#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> //printf, readline, perror
# include <readline/readline.h> //readline, rl_*
# include <readline/history.h> //readline, rl_*
# include <stdlib.h> //malloc, free, exit, ttyslot, getenv
# include <unistd.h> //write, access, read, close, fork, getcwd, chdir, *stat, unlink, execve, dup*, pipe, isatty, ttyname, ttyslot, tcsetattr, tcgetattr
# include <sys/types.h> //open, wait*, kill, *stat, opendir, closedir
# include <sys/stat.h> //open, stat
# include <fcntl.h> //open
# include <sys/wait.h> //wait*
# include <signal.h> //signal, kill
# include <dirent.h> //*dir
# include <string.h> //strerror
# include <errno.h> //perror
# include <sys/ioctl.h> //ioctl
# include <termios.h> //tcsetattr, tcgetattr
# include <curses.h> //tgetent, tgetflag, tgetnum,tgetstr, tgoto, tputs
# include <term.h> //getent, tgetflag, tgetnum, tgetstr, tgoto, tputs

# include "../libft/libft.h" 

typedef struct s_io			t_io;
typedef struct s_token_cmds	t_token_cmds;
typedef struct s_cmds		t_cmds;
typedef struct s_env		t_env;
typedef struct s_data		t_data;
typedef struct s_is_active	t_is_active;

typedef enum e_error
{
	ALL_OK,
	ERR_CREAT,
	ERR_ID,
	ERR_EXEC,
	ERR_PIPE,
	ERR_RAFT,
	ERR_MALLOC
}	t_error;

typedef struct s_io
{
	char	*io[4];
	t_io	*next;
}				t_io;

typedef struct s_token_cmds
{
	char			*token_cmd;
	t_token_cmds	*next;
}					t_token_cmds;

typedef struct s_cmds
{
	int				index; //useless
	t_token_cmds	*s_token_cmds;
	t_io			*io;
	t_cmds			*next;
}					t_cmds;

typedef struct s_env
{
	char	*env_line;
	t_env	*next;
}					t_env;

typedef struct s_data
{
	t_cmds	*ls_cmds;
	t_io	*ls_io;
	t_env	*ls_env;
}			t_data;

typedef struct s_is_active
{
	bool	simple_quote;
	bool	double_quote;
	bool	simple_right_rafter;
	bool	double_right_rafter;
	bool	simple_left_rafter;
	bool	double_left_rafter;
	bool	dollar;
}			t_is_active;

/*ROOT------------------------*/
/*init.c*/
void	init_back_bool(t_is_active *booleans);
void	booleans_init(t_is_active *booleans);
void	data_init(t_data *data, char **env);
/*PARSING---------------------*/
/*parsing.c*/
void	parsing(char *prompt_line, t_data *data);
/*manage_pipe*/
int	manage_pipe(char *prompt_line, int *i, t_is_active *booleans, t_data *data, int *word_length);
/*manage_dollar.c*/
int		manage_dollar(char *prompt_line, t_is_active *booleans, t_data *data, int *i, int *word_length);
/*save_word.c*/
int		save_word(int *word_length, char *prompt_line, int *i, t_data *data, t_is_active *booleans);
/*manage_rafters.c*/
int		manage_right_rafter(char *prompt_line, int *i, t_is_active *booleans, t_data *data, int *word_length);
int		manage_left_rafter(char *prompt_line, int *i, t_is_active *booleans, t_data *data, int *word_length);
/*manage_quotes.c*/
int    manage_simple_quote(char *promptline, int *i, t_is_active *booleans, t_data *data, int *word_length);
int    manage_double_quote(char *promptline, int *i, t_is_active *booleans, t_data *data, int *word_length);
/*EXECUTION------------------------*/
/*execution*/
int		execution(t_data *data);
/*UTILS-----------------------------*/
/*utils/utils00.c*/
char	*ft_cutstr(char const *s, unsigned int start);
/*is_space.c*/
bool	ft_isspace(char c);
/*print tabs*/
void	ft_print_tab(t_data *data);

#endif
