/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:48:04 by mkocabas          #+#    #+#             */
/*   Updated: 2023/01/04 23:48:05 by mkocabas         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str2[i] == 0)
		return ((char *)str1);
	while (i < len && str1[i] != '\0')
	{
		j = 0;
		while (str1[i + j] == str2[j] && (i + j < len))
		{
			j++;
			if (str2[j] == '\0')
				return ((char *)(str1 + i));
		}
		i++;
	}
	return (NULL);
}
