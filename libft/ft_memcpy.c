/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:59:02 by dea               #+#    #+#             */
/*   Updated: 2014/11/20 14:53:14 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*s1;
	const char		*s2;

	i = 0;
	s1 = dst;
	s2 = src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
