/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateFiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/12 22:14:03 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	create_files(t_cmdlist *node)
{
	t_filelist	*temp_file;

	if (!node)
		return ;
	run_heradocs(node);
	if (g_core.exec_output || !node)
		return ;
	while (node)
	{
		temp_file = node->files;
		while (temp_file)
		{
			if (*temp_file->metachar == *SINGLE_GREAT)
				create_outfile(node, temp_file);
			else
				create_infile(node, temp_file);
			if (temp_file->fd == SSTDERR)
			{
				g_core.exec_output = 1;
				break ;
			}
			temp_file = temp_file->next;
		}
		node = node->next;
	}
}
