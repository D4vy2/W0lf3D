/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 13:42:02 by dea               #+#    #+#             */
/*   Updated: 2015/07/10 15:37:13 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (j);
}

static void		ft_put_on_tab(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	size_t	index;

	i = 0;
	j = 0;
	index = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > j)
		{
			tab[index] = ft_strsub(s, j, i - j);
			index++;
		}
	}
	tab[index] = "\0";
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		len;

	if (!s)
		return (NULL);
	len = ft_count_word(s, c);
	tab = (char**)malloc(sizeof(char*) * len + 1);
	ft_put_on_tab(tab, s, c);
	return (tab);
}
