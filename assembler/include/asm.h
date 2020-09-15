/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:18:22 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/15 15:39:11 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

typedef struct		s_file
{
	int				fd;
	int				line;
	int				quotes;
	char			*name;
	char			comment[COMMENT_LENGTH];
	char			playername[PROG_NAME_LENGTH];
	unsigned char	code[CHAMP_MAX_SIZE];
	char			*labels[CHAMP_MAX_SIZE];
}					t_file;

typedef struct		s_instr
{
	int				opcode;
	int				acb;
	int				reg;
	char			*dir;
	char			*ind;
	struct s_instr	*next;
}					t_instruction;

typedef struct		s_code
{
	char			*label;
	t_instruction	*instr;
	struct s_code	*next;
}					t_code;

void				file_init(t_file *file);

int					valid_input(char *filename, t_file *file);
int					valid_reg(char **cmd, int i);
int					valid_dir(char **cmd, int i);
int					valid_ind(char **cmd, int i);
int					lexicon_error(char **cmd, int i, char *err, int ret);
int					end_quote(char **cmd, t_file *file, int modif);

int					verify_code(t_file *file, char *line, int l, int s);
int					is_head(char **cmd, char *str, int line, unsigned int i);
int					is_label(char **cmd);
int					is_opcode(char **cmd, int i, int line);

#endif
