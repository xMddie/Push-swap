/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:46:28 by mnau              #+#    #+#             */
/*   Updated: 2023/02/06 17:28:53 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

long	ft_atol(const char *str)
{
	int		i;
	int		negative;
	long	v;

	i = 0;
	v = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		v = (str[i] - '0') + (v * 10);
		i++;
	}
	return (v * negative);
}

int	ft_size(char *split)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (split[i] != ' ')
		count++;
	while (split[i])
	{
		if (split[i] == ' ' && split[i + 1] && split[i + 1] != ' ')
			count++;
		i++;
	}
	return (count);
}

void	ft_reverse(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}

void	ft_free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}
