/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 18:36:23 by dea               #+#    #+#             */
/*   Updated: 2014/11/19 13:41:20 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_count(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nb;

	nb = n;
	len = ft_count(n);
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	str[--len] = nb % 10 + 48;
	while (nb /= 10)
	{
		str[--len] = nb % 10 + 48;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
