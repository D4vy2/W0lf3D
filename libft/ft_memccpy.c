/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:20:04 by dea               #+#    #+#             */
/*   Updated: 2014/11/25 19:10:33 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*s1;
	const char		*s2;

	i = 0;
	s1 = (char*)dst;
	s2 = (const char*)src;
	while (i < n)
	{
		if (s2[i] == (char)c)
			return (&s1[i] + 1);
		else
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (NULL);
}
