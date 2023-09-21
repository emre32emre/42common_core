/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkocabas <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:50:08 by mkocabas          #+#    #+#             */
/*   Updated: 2023/01/04 23:50:12 by mkocabas         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int x)
{
	if (97 <= x && 122 >= x)
		x -= 32;
	return (x);
}
