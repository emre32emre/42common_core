/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunEnv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/12 22:18:03 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	run_env(t_cmdlist *cmd_node)
{
	t_env	*temp_env;

	temp_env = g_core.env_table;
	while (temp_env)
	{
		if (temp_env->content)
		{
			write(cmd_node->outfile, temp_env->env_name,
				ft_strlen(temp_env->env_name));
			write(cmd_node->outfile, "=", 1);
			write(cmd_node->outfile, temp_env->content,
				ft_strlen(temp_env->content));
			write(cmd_node->outfile, "\n", 1);
		}
		temp_env = temp_env->next;
		g_core.exec_output = 0;
	}
}
