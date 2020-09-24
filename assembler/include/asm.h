/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:18:22 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/24 14:03:44 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"

typedef	struct		s_args
{
	int				reg;
	char			*dir;
	char			*ind;
	struct s_args	*next;
}					t_args;

typedef struct		s_instr
{
	t_uchar			opcode;
	t_uchar			nargs;
	t_uchar			acb;
	t_args			*args;
	struct s_instr	*next;
}					t_instruction;

typedef struct		s_code
{
	char			*label;
	t_instruction	*instr;
	struct s_code	*next;
}					t_code;

typedef struct		s_file
{
	int				fd;
	int				line;
	int				quotes;
	int				prog_size;
	int				exec_magic;
	char			*name;
	char			comment[COMMENT_LENGTH];
	char			playername[PROG_NAME_LENGTH];
	unsigned char	code[CHAMP_MAX_SIZE];
	unsigned char	magic_nb[4];
	t_code			*code_tab;
}					t_file;

int					translate(t_file *file, int verbosity);

void				file_init(t_file *file, char *name);
t_code				*new_label(void);
t_instruction		*new_instruction(void);
t_args				*new_args(void);

int					file_destructor(t_file *file);
void				fill_header(char *dest, char *inst, int size, int err);
void				add_label(t_file *file, char *label);
void				add_instruction(t_file *file, char **cmd, int i);
void				add_arg(t_instruction *instr, int reg, char *dir, char *ind);
void				load_params(char **cmd, int x, int i, t_instruction *instr);
void				load_op(char **cmd, int i, t_instruction *instr);

int					valid_input(t_file *file);
int					valid_reg(char **cmd, int i);
int					valid_dir(char **cmd, int i);
int					valid_ind(char **cmd, int i);
int					valid_params(char **cmd, int x, int i, int line);
int					valid_separator(char **cmd, int i, int nargs, int line);
int					end_quote(char **cmd, t_file *file, int modif);
int					lexicon_error(char **cmd, int i, char *err, int line);
int					syntax_error(char **cmd, int i, char *err, int line);
int					load_error(char **cmd, int i, char *err, int line);

int					verify_code(t_file *file, char *line, int l, int s);
int					is_head(char **cmd, char *str, int line, unsigned int i);
int					is_label(char **cmd);
int					is_opcode(char **cmd, int i, int line);

void				collecting_codebytes(t_file *file);
int					writing_exec(t_file *file);
#endif
