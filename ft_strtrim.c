/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:30:06 by pmaury            #+#    #+#             */
/*   Updated: 2021/03/30 11:30:07 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	j = 0;
	while ((s1[i + j]) && (!(is_in_set(s1[i + j], set))))
		j++;
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (0);
	str[j] = 0;
	while (j--)
		str[j] = s1[i + j];
	return (str);
}