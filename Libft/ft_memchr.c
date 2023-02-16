/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:24:06 by mnau              #+#    #+#             */
/*   Updated: 2022/11/24 10:44:36 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	unsigned const char	*pstr;

	pstr = (unsigned const char *)str;
	while (size)
	{
		if (*pstr == (unsigned char)c)
			return ((unsigned char *)pstr);
		pstr++;
		size--;
	}
	return (NULL);
}
