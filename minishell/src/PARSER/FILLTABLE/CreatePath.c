/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreatePath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/12 22:14:16 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

char	**create_path(t_lexlist *lex_list)
{
	int		count;
	char	**path;

	count = 0;
	while (lex_list && lex_list->type != SIGN_PIPE)
	{
		if (lex_list->type == TEXT && lex_list->content)
			count++;
		else
		{
			lex_list = lex_list->next;
			if (lex_list)
				lex_list = lex_list->next;
			continue ;
		}
		lex_list = lex_list->next;
	}
	if (!count)
		return (NULL);
	path = (char **)malloc(sizeof(char *) * (count + 1));
	path[count] = NULL;
	return (path);
}
