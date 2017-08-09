/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:08:57 by dea               #+#    #+#             */
/*   Updated: 2014/11/15 20:44:24 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	total;
	size_t	i;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	total = len_d + len_s;
	if (size >= len_d)
	{
		while (len_d < (size - 1))
		{
			dst[len_d] = src[i];
			len_d++;
			i++;
		}
		dst[len_d] = '\0';
		return (total);
	}
	return (size + len_s);
}
