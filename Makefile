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
DSRC			=	src
DOBJ			=	obj
DHEADER			=	header
DLIBFT			=	libft

#####################################################
#					FLAGS							#
#####################################################
CFLAGS		=	-Wall -Wextra -Werror -g3 -g
LFLAGS		=	-lreadline -lncurses

#####################################################
#					FILES							#
#####################################################
CFILES		=	main.c\
				
CHEADERS	=	minishell.h
SRC			=	$(DSRC)/$(CFILES)
HEADERS		=	$(DHEADER)/$(CHEADERS)
OBJ			=	$(CFILES:%.c=$(DOBJ)/%.o)


#####################################################
#					ARCHIVES						#
#####################################################
 LIBFT		=	libft/libft.a\
 				libft/printf/libftprintf.a\
 				libft/printf_err/libftprintf.a\

all :
	$(MAKE) -C $(DLIBFT)/
	$(MAKE) $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(DOBJ)/%.o : $(DSRC)/%.c $(HEADERS) Makefile | $(DOBJ)
	$(CC) $(CFLAGS) -o $@ -c $<

$(DOBJ):
	mkdir -p $(DOBJ)


re: fclean
	$(MAKE) all

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(DLIBFT)/

clean :
	rm -rf $(DOBJ)
	$(MAKE) clean -C $(DLIBFT)/
