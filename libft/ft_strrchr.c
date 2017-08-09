/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:00:17 by dea               #+#    #+#             */
/*   Updated: 2014/11/22 09:36:12 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	int		len2;

	i = 0;
	len = ft_strlen(s);
	len2 = ft_strlen(s);
	while (len >= i)
	{
		if (s[len] == c)
			return ((char*)&s[len]);
		len--;
	}
	if (c == '\0')
		return ((char*)&s[len2]);
	else
		return (NULL);
}
