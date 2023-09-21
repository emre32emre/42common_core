/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunExecve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/12 22:16:37 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"

void	run_execve(t_cmdlist *cmd_node, int *fd, int fd_index)
{
	char	**envlist;

	cmd_node->pid = fork();
	if (!cmd_node->pid)
	{
		create_dup(cmd_node, fd, fd_index);
		envlist = get_env_cpy();
		if (execve(cmd_node->cmd, cmd_node->path, envlist) == -1)
		{
			if (cmd_node->cmd)
				print_error(cmd_node->cmd, " command not found\n", NULL);
			free_env_cpy(envlist);
			free_for_loop();
			free_core();
			exit(127);
		}
	}
	if (fd && cmd_node->pid)
		clear_pipe(fd);
	waitpid(cmd_node->pid, &g_core.exec_output, 0);
	g_core.exec_output = WEXITSTATUS(g_core.exec_output);
}
