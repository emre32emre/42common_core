/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DupFunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/12 22:16:45 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

void	create_dup(t_cmdlist *cmd_list, int *fd, int fd_index)
{
	int	new_fd[2];

	if (cmd_list->infile == HERADOC)
	{
		pipe(new_fd);
		write(new_fd[1], cmd_list->heradoc_values,
			ft_strlen(cmd_list->heradoc_values));
		dup2(new_fd[0], 0);
		close (new_fd[1]);
		close(new_fd[0]);
	}
	else if (cmd_list->infile > SSTDERR)
		dup2(cmd_list->infile, 0);
	else if (fd && cmd_list != g_core.cmd_table)
		dup2(fd[fd_index - 2], 0);
	if (cmd_list->outfile > SSTDERR)
		dup2(cmd_list->outfile, 1);
	else if (fd && cmd_list->next)
		dup2(fd[fd_index + 1], 1);
	if (fd_index >= 0)
		clear_pipe(fd);
}
