/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:08:43 by dea               #+#    #+#             */
/*   Updated: 2014/11/25 19:11:29 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1_;
	unsigned char	*s2_;

	i = 0;
	s1_ = (unsigned char*)s1;
	s2_ = (unsigned char*)s2;
	if (n == 0 || !s1 || !s2)
		return (0);
	while (i < n)
	{
		if (s1_[i] != s2_[i])
			return (s1_[i] - s2_[i]);
		i++;
	}
	return (0);
}
