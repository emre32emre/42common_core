/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/12 22:10:46 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	free_core(void)
{
	free_metachars();
	free_envtable();
	rl_clear_history();
}

void	free_for_loop(void)
{
	if (g_core.cmd)
	{
		free(g_core.cmd);
		g_core.cmd = NULL;
	}
	if (g_core.lex_table)
		free_lexer();
	if (g_core.cmd_table)
		free_parser();
	close_heradoc_file();
}
