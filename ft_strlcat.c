/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:28:13 by pmaury            #+#    #+#             */
/*   Updated: 2021/03/30 11:28:15 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	while (j < size && dest[j])
		j++;
	if (j == size)
		return (size + i);
	if (i < size - j)
		ft_memcpy(dest + j, src, i + 1);
	else
	{
		ft_memcpy(dest + j, src, size - j - 1);
		dest[size - 1] = 0;
	}
	return (i + j);
}
