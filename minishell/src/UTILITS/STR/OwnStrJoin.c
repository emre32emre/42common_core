/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OwnStrJoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/12 22:11:08 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	own_strjoin(char **dst, char *src)
{
	char	*ptr;
	char	*holder_ptr;
	char	*holder_dst;
	size_t	len;

	if (!*dst && !src)
		return ;
	len = ft_strlen(*dst) + ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	ptr[len] = 0;
	holder_ptr = ptr;
	holder_dst = *dst;
	while (holder_dst && *holder_dst)
		*(holder_ptr++) = *(holder_dst++);
	while (src && *src)
		*(holder_ptr++) = *(src++);
	if (*dst)
		free(*dst);
	*dst = ptr;
}
