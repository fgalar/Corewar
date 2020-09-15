/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:11:34 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/15 18:18:14 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "asm.h"

void	free_instruction(char **cmd, char *pitcher, char *line, int fd)
{
	if (fd >= 0)
		close(fd);
	if (cmd)
		free_split(cmd);
	if (pitcher)
		free(pitcher);
	if (line)
		free(line);
}

int		invalid_lexicon(char **cmd, int line, t_file *file)
{
	int err;
	int	pos;

	err = 0;
	pos = 0;
	if (file->quotes && (err = end_quote(cmd, file, 0)) == 1)
		return (0);
	if (err == 0 && ((err = is_head(cmd, ".name", line, 0)) == 1 || err == 2))
		return (0);
	if (err == 0 && ((err = is_head(cmd, ".comment", line, 0)) < 3 && err))
		return (0);
	if (err == 0)
		pos = is_label(cmd);
	if (err == 0 && (err = is_opcode(cmd, pos, line)) == 1)
		return (0);
	return ((err < 0) ? 1 : 0);
}

int		invalid_syntax(char **cmd, int i, t_file *file, char *inst)
{
	int	err;

	err = 0;
	if (file->quotes)
		end_quote(cmd, file, 0);
	if (file->quotes == 1 || (!err && ((err = is_head(cmd, ".name", file->line,
								0)) == 1 || err == 2) && !file->playername[0]))
	{
		fill_header(file->playername, inst, PROG_NAME_LENGTH, err);
		file->quotes = (err == 1) ? 1 : 0;
		return (0);
	}
	if (file->quotes == 2 || (!err && ((err = is_head(cmd, ".comment",
							file->line, 0)) < 3 && err) && !file->comment[0]))
	{
		fill_header(file->comment, inst, COMMENT_LENGTH, err);
		file->quotes = (err == 1) ? 2 : 0;
		return (0);
	}
	if (is_label(cmd))
	{
		//create new label_node in the table which contains its instruction nodes
		ft_printf(BLUE"LABEL: %s\n"E0M, cmd[i]);
	}
	return (0);
}

int		verify_code(t_file *file, char *line, int l, int s)
{
	char	*pitcher;
	char	**cmd;
	int		i;

	pitcher = NULL;
	i = 1;
	while (get_next_line2(file->fd, &line, &pitcher) == 1)
	{
		cmd = ft_split(line, " \t");
		file->line = i;
		if (cmd && cmd[0])
		{
			l = invalid_lexicon(cmd, i, file);
			if (l || (s = invalid_syntax(cmd, 0, file, line)))
			{
				free_instruction(cmd, pitcher, line, file->fd);
				return (EXIT_FAILURE);
			}
		}
		i++;
		free_instruction(cmd, NULL, line, -1);
	}
	ft_printf(GREEN"NAME: "CYAN"%s\n"E0M, file->playername);
	ft_printf(GREEN"COMMENT: "CYAN"%s\n"E0M, file->comment);
	free_instruction(NULL, NULL, line, file->fd);
	return (EXIT_SUCCESS);
}
