/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:02:32 by mnau              #+#    #+#             */
/*   Updated: 2022/11/11 16:24:35 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t		i;
	char		*pdest;
	const char	*psrc;

	i = 0;
	pdest = (char *)dest;
	psrc = (const char *)src;
	if (pdest == NULL && psrc == NULL)
		return (pdest);
	while (size > 0)
	{
		pdest[i] = psrc[i];
		i++;
		size--;
	}
	return (dest);
}
