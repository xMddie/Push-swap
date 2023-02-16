/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinyalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:57:56 by mnau              #+#    #+#             */
/*   Updated: 2023/01/27 20:20:39 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort3(t_stack *stack)
{
	if (stack->tab[0] > stack->tab[1] && stack->tab[1] < stack->tab[2]
		&& stack->tab[2] > stack->tab[0])
		sa(stack);
	else if (stack->tab[0] < stack->tab[1] && stack->tab[1] > stack->tab[2]
		&& stack->tab[2] < stack->tab[0])
		revrotate(stack, 'a');
	else if (stack->tab[0] > stack->tab[1] && stack->tab[1] > stack->tab[2]
		&& stack->tab[2] < stack->tab[0])
	{
		sa(stack);
		revrotate(stack, 'a');
	}
	else if (stack->tab[0] < stack->tab[1] && stack->tab[1] > stack->tab[2]
		&& stack->tab[2] > stack->tab[0])
	{
		sa(stack);
		r_moves(stack, 'a');
	}
	else if (stack->tab[0] > stack->tab[1] && stack->tab[1] < stack->tab[2]
		&& stack->tab[2] < stack->tab[0])
		r_moves(stack, 'a');
}

void	ft_tinysort(t_stack *stack)
{
	if (stack->size == 2)
	{
		if (stack->tab[0] > stack->tab[1])
			sa(stack);
	}
	else if (stack->size == 3)
		ft_sort3(stack);
}
