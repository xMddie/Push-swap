/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:00:32 by mnau              #+#    #+#             */
/*   Updated: 2022/11/20 11:00:52 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	char			*str;
	unsigned int	j;

	j = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen((char *)s) < (len))
	{
		j = ft_strlen(s + start) + 1;
		str = malloc(sizeof(char) * j);
	}
	else
	{
		j = len + 1;
		str = malloc(sizeof(char) * j);
	}
	if (str == 0)
		return (0);
	j = ft_strlcpy(str, &s[start], j);
	return (str);
}
