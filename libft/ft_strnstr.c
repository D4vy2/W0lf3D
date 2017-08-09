/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 10:15:19 by dea               #+#    #+#             */
/*   Updated: 2014/11/12 14:32:32 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!s2[j])
		return ((char*)&s1[i]);
	while (s1[i] && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i] == s2[j] && i < n)
			{
				i++;
				j++;
				if (s2[j] == '\0')
					return ((char *)&s1[i] - j);
			}
			i++;
		}
		i++;
	}
	return (NULL);
}
