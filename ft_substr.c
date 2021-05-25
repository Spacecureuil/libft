/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:30:17 by pmaury            #+#    #+#             */
/*   Updated: 2021/03/30 11:30:18 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*substr;
	unsigned int	j;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	j = ft_strlen(s + start);
	if (j > len)
		j = len;
	if (s_len < start)
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * (j + 1));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
