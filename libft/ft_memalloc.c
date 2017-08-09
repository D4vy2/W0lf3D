/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:44:04 by dea               #+#    #+#             */
/*   Updated: 2014/12/03 12:16:43 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void *ft_memalloc(size_t size)
{
	void	*memory;

	memory = (void*)malloc(size);
	if (memory == NULL)
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
