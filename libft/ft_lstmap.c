/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 11:47:22 by dea               #+#    #+#             */
/*   Updated: 2014/11/28 12:38:48 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *temp;
	t_list *cross;

	temp = lst;
	cross = lst;
	while (temp != NULL)
	{
		cross = cross->next;
		temp = f(temp);
		temp = ft_lstnew(temp->content, temp->content_size);
		temp = cross;
	}
	temp = NULL;
	return (lst);
}
