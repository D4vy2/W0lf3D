/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 17:21:09 by dea               #+#    #+#             */
/*   Updated: 2014/11/28 11:50:12 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!alst || !del)
		return ;
	temp = (*alst)->next;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
	*alst = temp;
}
