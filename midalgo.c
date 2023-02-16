/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midalgo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:56:32 by mnau              #+#    #+#             */
/*   Updated: 2023/02/02 12:01:52 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findlittlenb(t_stack	*stack)
{
	int	i;
	int	min;

	if (!stack || !stack->tab)
		return (0);
	i = 0;
	min = stack->tab[0];
	while (i < stack->size)
	{
		if (min > stack->tab[i])
			min = stack->tab[i];
		i++;
	}
	return (min);
}

static void	ft_pushmin(t_stack *astack, t_stack *bstack)
{
	int	idx;
	int	j;

	idx = 0;
	j = ft_findlittlenb(astack);
	while (astack->tab[idx] != j)
		idx++;
	if (idx < astack->size / 2)
	{
		while (astack->tab[0] != j)
			r_moves(astack, 'a');
	}
	else
	{
		while (astack->tab[0] != j)
			revrotate(astack, 'a');
	}
	pb(astack, bstack);
}

void	ft_midsort(t_stack *astack, t_stack *bstack)
{
	if (astack->size >= 4)
	{
		while (astack->size > 3)
			ft_pushmin(astack, bstack);
		ft_tinysort(astack);
		while (bstack->size > 0)
			pa(astack, bstack);
	}
}
