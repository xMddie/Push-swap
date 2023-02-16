/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigalgo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:02:13 by mnau              #+#    #+#             */
/*   Updated: 2023/02/02 21:11:38 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findfirstchain(t_stack *a)
{
	int	idx[2];
	int	index;
	int	res;

	idx[0] = 0;
	idx[1] = 0;
	index = 0;
	res = 0;
	while (idx[0] < a->size)
	{
		if (a->tab[idx[0]] < a->tab[idx[0] + 1])
		{
			if (res <= idx[1])
				index = idx[0] - idx[1];
			idx[1]++;
		}
		else
		{
			if (res < idx[1])
				res = idx[1];
			idx[1] = 0;
		}
		idx[0]++;
	}
	return (index);
}

void	sendtob(t_stack *a, t_stack *b)
{
	int	i;
	int	idx;
	int	len;

	i = 0;
	idx = findfirstchain(a);
	len = findchain(a);
	while (i < idx)
	{
		pb(a, b);
		i++;
	}
	while (a->size > len)
	{	
		revrotate(a, 'a');
		pb(a, b);
	}
	while (a->tab[0] > a->tab[a->size - 1])
		revrotate (a, 'a');
}

int	find_mv_nb_a(t_stack *a, t_stack *b, int step)
{
	int	idx;

	idx = get_next_max(a, b->tab[step]);
	if (idx <= a->size / 2)
		return (idx);
	else
		return ((a->size) - idx);
}

int	*stockcount(t_stack *a, t_stack *b)
{
	int	*tabcount;
	int	idx[4];
	int	i;

	tabcount = ft_calloc(b->size, sizeof(int *));
	i = 0;
	while (i < 3)
		idx[i++] = 0;
	while (idx[0]++ < b->size)
	{
		if (idx[0] <= b->size / 2)
			idx[3] = idx[0];
		else
			idx[3] = b->size - idx[0];
		tabcount[idx[1]++] = idx[3] + find_mv_nb_a(a, b, idx[1]) + 1;
		idx[3] = 0;
	}
	return (tabcount);
}
