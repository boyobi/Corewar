# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbetz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/12 14:39:25 by bbetz             #+#    #+#              #
#    Updated: 2017/03/15 16:20:13 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Main
NAME	=	libft.a
AR		=	ar -rcs
CC		=	gcc

ifeq ($(DEBUG), yes)
FDEBUG	=	-Wextra -Wall -Werror
endif

WFLAGS	=	-Wall -Wextra -Werror -g
OPTI	=	-I
LS		=	ls -1
GREP	=	grep
MKDIR	=	mkdir -p
RM		=	rm -rf

# Directory
DSRC	=	sources
DOBJ	=	objets
DINC	=	include

# File
FSRC	:=	$(shell $(LS) $(DSRC) | $(GREP) \.c$)
FOBJ	:=	$(FSRC:.c=.o)

# Transform
FSRC	:=	$(addprefix $(DSRC)/, $(FSRC))
FOBJ	:=	$(addprefix $(DOBJ)/, $(FOBJ))
FINC	:=	$(addprefix $(OPTI) , $(DINC))

GRN = \033[1;32m
CLN = \033[m
WHT = \033[1;37m
CLEANED = $(WHT)"cleaned"$(CLN)
FCLEANED = $(WHT)"fcleaned"$(CLN)
COMPILED = $(GRN)"compiled"$(CLN)

all: $(FOBJ) $(NAME)

$(NAME): $(FOBJ)
	@echo "libft compiling... \c"
	@$(AR) $@ $(FOBJ)
	@echo "$(COMPILED)"

$(DOBJ)/%.o: $(DSRC)/%.c $(DINC)
	@$(MKDIR) $(DOBJ)
	@$(CC) $(FDEBUG) $(WFLAGS) -c $< $(FINC) -o $@

clean:
	@$(RM) $(DOBJ)
	@echo "libft $(CLEANED)"

fclean: clean
	@$(RM) $(NAME)
	@echo "libft $(FCLEANED)"

re: fclean all

.PHONY: all begin clean fclean re
