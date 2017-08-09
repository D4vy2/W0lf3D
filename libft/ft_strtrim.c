/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:28:06 by dea               #+#    #+#             */
/*   Updated: 2014/12/03 11:55:15 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (ft_strlen(s) > 0)
		i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	new = ft_strnew(i);
	if (new)
	{
		while (i)
		{
			new[i] = s[i];
			i--;
		}
		new[i] = s[i];
	}
	return (new);
}
