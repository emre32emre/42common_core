/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/21 19:46:02 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	init_core(char **env)
{
	fill_envs(env);
	set_metachars();
	g_core.exec_output = 0;
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc != 1)
	{
		printf("You do not need to enter args...\n");
		return (0);
	}
	init_core(env);
	signal(SIGINT, signals);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		g_core.cmd = readline("\033[0;34m <Kojima's Dungeon>-> \033[0m");
		lexer();
		expander();
		parser();
		executer();
		add_history(g_core.cmd);
		exit_signal_check();
		free_for_loop();
	}
	free_core();
}
