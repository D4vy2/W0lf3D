/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:58:05 by dea               #+#    #+#             */
/*   Updated: 2014/11/12 13:04:09 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	char			*s1;
	const char		*s2;
	char			temp[len];

	i = 0;
	s1 = dst;
	s2 = src;
	while (i < len)
	{
		temp[i] = s2[i];
		i++;
	}
	temp[i] = '\0';
	i = 0;
	while (i < len)
	{
		s1[i] = temp[i];
		i++;
	}
	return (s1);
}
