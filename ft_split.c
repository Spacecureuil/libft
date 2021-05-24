/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:47:13 by pmaury            #+#    #+#             */
/*   Updated: 2021/03/30 11:47:18 by pmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_strndup(char *src, int n)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int		count_words(char *str, char charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		if (str[i])
		{
			words++;
			while (str[i] && str[i] != charset)
				i++;
		}
	}
	return (words);
}

static int		count_words_len(char *str, char charset)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != charset)
		len++;
	return (len);
}


static int		get_word(char *str, char charset, char ***tab, int j)
{
	int	i;

	i = count_words_len(str, charset);
	(*tab)[j] = ft_strndup(str, i);
	if (!((*tab)[j]))
	{	
		while (j-- >= 0)
			free((*tab)[j]);
		free(*tab);
		*tab = NULL;
	}
	return (i);
}

char			**ft_split(char const *str, char charset)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc((count_words((char*)str, charset) + 1) * sizeof(char *));
	while (tab && str[i])
	{
		if (str[i] && str[i] != charset)
			i += get_word((char*)&str[i], charset, &tab, j++);
		else
			i++;
	}
	if (tab)
		tab[j] = 0;
	return (tab);
}
