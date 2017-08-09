/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:47:33 by dea               #+#    #+#             */
/*   Updated: 2014/11/22 09:47:01 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (dst);
	while (i < n)
	{
		while (src[i] && i < n)
		{
			dst[i] = src[i];
			i++;
		}
		while (i < n)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
