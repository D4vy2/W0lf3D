/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:24:23 by dea               #+#    #+#             */
/*   Updated: 2014/11/15 20:46:57 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	symbol;
	int	result;

	result = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	symbol = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]) == 1)
	{
		while (ft_isdigit(str[i]) == 1)
			result = result * 10 + (str[i++] - 48);
	}
	return (symbol * result);
}
