/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigalgo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:19:21 by mnau              #+#    #+#             */
/*   Updated: 2023/02/03 13:34:18 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findidx_a(t_stack *a, int value)
{
	int	idx;

	idx = get_next_max(a, value);
	return (idx);
}

int	findlessmv(int *tabcount)
{
	int	i;
	int	stock;

	i = 0;
	stock = 1;
	if (stock <= tabcount[i])
		stock = i;
	while (tabcount[i])
	{
		if (tabcount[stock] > tabcount[i])
			stock = i;
		i++;
	}
	return (stock);
}

void	do_mv_opti(t_stack *a)
{
	if (get_max_index(a) <= a->size / 2)
		while (get_max_index(a) != a->size - 1)
			r_moves(a, 'a');
	else
		while (get_max_index(a) != a->size - 1)
			revrotate(a, 'a');
}

void	do_mv(t_stack *a, t_stack *b)
{
	int	number;
	int	number_a;
	int	*tab;

	tab = stockcount(a, b);
	number = b->tab[findlessmv(tab)];
	number_a = a->tab[findidx_a(a, number)];
	if (findlessmv(tab) <= b->size / 2)
		while (b->tab[0] != number)
			r_moves(b, 'b');
	else
		while (b->tab[0] != number)
			revrotate(b, 'b');
	if (findidx_a(a, number) <= a->size / 2)
		while (a->tab[0] != number_a)
			r_moves(a, 'a');
	else
		while (a->tab[0] != number_a)
			revrotate(a, 'a');
	pa(a, b);
	if (!b->size)
		do_mv_opti(a);
	free(tab);
}
