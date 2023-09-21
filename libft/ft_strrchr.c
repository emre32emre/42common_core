/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:48:41 by mkocabas          #+#    #+#             */
/*   Updated: 2023/01/04 23:48:43 by mkocabas         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*rslt;
	int		len;

	i = 0;
	rslt = (char *)s;
	len = (ft_strlen(s));
	while (i <= len)
	{
		if (rslt[len] == (char)c)
			return (rslt + len);
		len--;
	}
	return (NULL);
}
