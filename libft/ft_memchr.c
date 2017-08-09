/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 11:46:49 by dea               #+#    #+#             */
/*   Updated: 2014/11/15 16:10:50 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	ch;

	if (!s)
		return (NULL);
	i = 0;
	ch = (unsigned char)c;
	s1 = (unsigned char*)s;
	while (i < n)
	{
		if (s1[i] == ch)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
