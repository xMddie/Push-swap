/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:39:23 by mnau              #+#    #+#             */
/*   Updated: 2022/11/15 17:30:23 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchedc)
{
	char	i;

	i = searchedc;
	if (i == '\0')
	{
		while (*str)
		{
			str++;
		}
		return ((char *)str);
	}
	while (*str)
	{
		if (*str == i)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
