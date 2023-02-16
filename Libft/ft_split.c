/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:07:28 by mnau              #+#    #+#             */
/*   Updated: 2022/11/19 09:40:19 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
			word++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		idx[3];
	char	**str;

	idx[0] = 0;
	idx[2] = 0;
	if (!s)
		return (0);
	str = malloc((sizeof(char *)) * (ft_countword((char *)s, c) + 1));
	if (!str)
		return (0);
	while (s[idx[0]])
	{
		idx[1] = idx[0];
		while (s[idx[0]] && s[idx[0]] != c)
			idx[0]++;
		if (idx[1] != idx[0])
			str[idx[2]++] = ft_substr(s, idx[1], idx[0] - idx[1]);
		while (s[idx[0]] && s[idx[0]] == c)
			idx[0]++;
	}
	str[idx[2]] = 0;
	return (str);
}
