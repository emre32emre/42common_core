/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PipeFunction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/12 22:22:53 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

int	*create_pipe(void)
{
	int		index;
	int		*fd;

	fd = (int *)malloc(sizeof(int) * 6);
	index = -1;
	while (++index < 6)
		fd[index] = 0;
	return (fd);
}

void	clear_pipe(int *fd)
{
	int	index;

	if (fd)
	{
		index = -1;
		while (++index < 6)
		{
			if (fd[index])
				close(fd[index]);
		}
		free(fd);
	}
}

void	switch_pipe(int **fd)
{
	int	temp;

	temp = (*fd)[0];
	(*fd)[0] = (*fd)[2];
	(*fd)[2] = temp;
	temp = (*fd)[1];
	(*fd)[1] = (*fd)[3];
	(*fd)[3] = temp;
	temp = (*fd)[5];
	(*fd)[5] = (*fd)[3];
	(*fd)[3] = temp;
	temp = (*fd)[2];
	(*fd)[2] = (*fd)[4];
	(*fd)[4] = temp;
}
