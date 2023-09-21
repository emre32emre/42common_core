/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <mkocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:26:28 by mkocabas          #+#    #+#             */
/*   Updated: 2023/08/12 22:06:49 by mkocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

char	*ft_strpcpy(char *dst, char *src, int count)
{
	char	*ptr;
	char	*return_ptr;
	int		index;

	if (!src || !count)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(dst) + count + 1));
	return_ptr = ptr;
	index = -1;
	while (dst && *dst)
		*(ptr++) = *(dst++);
	while (++index < count && src && *src)
		*(ptr++) = *(src++);
	*ptr = 0;
	return (return_ptr);
}
