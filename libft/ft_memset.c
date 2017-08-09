/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:51:48 by dea               #+#    #+#             */
/*   Updated: 2014/11/12 13:02:13 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned char	ch;

	i = 0;
	str = b;
	ch = c;
	while (i < len)
	{
		str[i] = ch;
		i++;
	}
	return (b);
}
