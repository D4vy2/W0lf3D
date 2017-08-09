/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 12:17:57 by dea               #+#    #+#             */
/*   Updated: 2014/11/28 09:58:36 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!alst || !*alst || !del)
		return ;
	temp = *alst;
	while (temp != NULL)
	{
		*alst = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = *alst;
	}
}
