#####################################################
#					PROGRAM							#
#####################################################
NAME		=	minishell

#####################################################
#					COMPILING						#
#####################################################
CC			=	cc

#####################################################
#					DIRECTORY						#
#####################################################
DIR_SRC			=	src
DIR_EXEC        =   execution
DIR_PARS        =   parsing
DIR_UTILS       =   utils
DIR_OBJ			=	obj
DIR_HEADER		=	header
DIR_LIBFT		=	libft

#####################################################
#					FLAGS							#
#####################################################
CFLAGS		=	-Wall -Wextra -Werror -g3 -g
LFLAGS		=	-lreadline -lncurses

#####################################################
#					FILES							#
#####################################################
FILES		=	main.c\
                init.c\
                $(DIR_EXEC)/$(FILES_EXEC)\
                $(DIR_PARS)/$(FILES_PARS)\
                $(DIR_UTILS)/$(FILES_UTILS)

FILES_EXEC  =   execution.c
FILES_PARS  =   parsing.c\
                manage_dollar.c\
                manage_pipe.c\
                manage_quotes.c\
                manage_rafters.c\
                save_word.c
FILES_UTILS =   ft_isspace.c\
                utils00.c
				
HEADERS		=	minishell.h
SRC			=	$(DIR_SRC)/$(FILES)
HEADERS		=	$(DIR_HEADER)/$(HEADERS)
OBJ			=	$(FILES:%.c=$(DIR_OBJ)/%.o)


#####################################################
#					ARCHIVES						#
#####################################################
 LIBFT		=	libft/libft.a\
 				libft/printf/libftprintf.a\
 				libft/printf_err/libftprintf.a\

all :
	$(MAKE) -C $(DIR_LIBFT)/
	$(MAKE) $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c $(HEADERS) Makefile | $(DIR_OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)


re: fclean
	$(MAKE) all

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(DIR_LIBFT)/

clean :
	rm -rf $(DIR_OBJ)
	$(MAKE) clean -C $(DIR_LIBFT)/
