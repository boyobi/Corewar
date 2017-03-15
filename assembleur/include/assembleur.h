/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembleur.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:03:26 by mmatamou          #+#    #+#             */
/*   Updated: 2017/03/13 20:51:22 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLEUR_H
# define ASSEMBLEUR_H

#include "../../include/global.h"

/**/
#include <stdio.h>
/**/

#define PARSE_ERROR		0b1
#define PARSE_name		0b10
#define PARSE_comment	0b100
#define	FIRST_OPCODE	0b1000

#define WRITER_SIZE		500
/*
#define 
*/

typedef struct		s_params
{
	t_op			*tab;
	int				count;
	unsigned char	coding_byte;	
	unsigned int	type[3];
	int				value[3];
	char			*(lbels[3]);
}					t_params;

typedef struct		s_writer
{
	int				char_counter;
	unsigned char	storer[WRITER_SIZE];
	struct s_writer	*prev;
	struct s_writer	*nxt;
}					t_writer;

typedef struct			s_commands
{
	int					gnl_ret;
	char				*label;
	char				*line;
	unsigned char		number_of_bytes;
	unsigned char		*output_to_file;
	t_params			p;
	struct s_commands	*prev;
	struct s_commands	*nxt;
}						t_commands;



/*
** <writer.c> Recording what will be written to the file and writing it
*/
void					writer_init(t_writer **w, t_writer *previous);
void					putchar_to_w(t_writer **w, unsigned char c);
void					putstr_to_w(t_writer **w, unsigned char *str);
void					put_w_to_file(t_writer *w, int cor_fd);

/*
** <check_commands.c> Record the lines after .name and .comment and check the for commands
*/
t_commands				*get_commands(int fd);

/*
** <chars_strs.c>
*/
int						comment_or_end(char c);
int						is_labelchars(char c);
void					trimard(char *line);
/*
** <handle_commands.c> 
*/
void					handle_commands(t_commands *cmd, int *infos);
/*
** <create_cor_file.c>
*/
void					create_cor_file(t_commands *cmd, char *n, char n_c_str[3000], int p);

void	name_comment(char *line, char n_c_str[3000], int *p, int *infos);
void	assembler(char *name);
//int		check_commands(char *line, int cor_fd, int *infos);
int		is_labelchars(char c);
int		parse_error(int	*infos, char *error_message);

#endif
