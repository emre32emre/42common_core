/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:43:52 by mkocabas          #+#    #+#             */
/*   Updated: 2023/01/05 00:01:47 by mkocabas         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	j_dest;
	size_t	i;

	len_src = ft_strlen(src);
	if (dest)
		len_dest = ft_strlen(dest);
	else
		len_dest = 0;
	j_dest = len_dest;
	i = 0;
	if (size == 0 || size < len_dest)
		return (len_src + size);
	while (src[i] != '\0' && j_dest < (size - 1))
	{
		dest[j_dest] = src[i];
		j_dest++;
		i++;
	}
	dest[j_dest] = '\0';
	return (len_dest + len_src);
}
