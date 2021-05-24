/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:14:42 by pmaury            #+#    #+#             */
/*   Updated: 2021/03/25 10:14:47 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!dest)
		return (0);
	i = 0;
	j = 0;
	while (str1[i])
	{
		dest[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		dest[i] = str2[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}
