/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:07:50 by dea               #+#    #+#             */
/*   Updated: 2014/11/19 15:47:10 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char*)malloc(sizeof(char) * size + 1);
	if (temp == NULL)
		return (NULL);
	while (i < size)
	{
		temp[i] = '\0';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
