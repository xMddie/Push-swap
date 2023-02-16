/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:31:06 by mnau              #+#    #+#             */
/*   Updated: 2023/02/02 15:04:08 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_moves(t_stack *stack, char c)
{
	int	tmp;

	tmp = stack->tab[0];
	ft_memmove(stack->tab, stack->tab + 1, stack->size * sizeof(int));
	stack->tab[stack->size - 1] = tmp;
	if (c == 'a')
		print_action("ra");
	if (c == 'b')
		print_action("rb");
}

void	rr_moves(t_stack *astack, t_stack *bstack)
{
	int	tmp;

	tmp = astack->tab[0];
	ft_memmove(astack->tab, astack->tab + 1, astack->size * sizeof(int));
	astack->tab[astack->size - 1] = tmp;
	tmp = bstack->tab[0];
	ft_memmove(bstack->tab, bstack->tab + 1, bstack->size * sizeof(int));
	bstack->tab[bstack->size - 1] = tmp;
	print_action("rr");
}

void	revrotate(t_stack *stack, char c)
{
	int	tmp;

	if (stack->size == 0)
		return ;
	tmp = stack->tab[stack->size - 1];
	ft_memmove(stack->tab + 1, stack->tab, stack->size * sizeof(int));
	stack->tab[0] = tmp;
	if (c == 'a')
		print_action("rra");
	if (c == 'b')
		print_action("rrb");
}

void	rrr_moves(t_stack *astack, t_stack *bstack)
{
	int	tmp;

	tmp = astack->tab[astack->size - 1];
	ft_memmove(astack->tab + 1, astack->tab, astack->size * sizeof(int));
	astack->tab[0] = tmp;
	tmp = bstack->tab[bstack->size - 1];
	ft_memmove(bstack->tab + 1, bstack->tab, bstack->size * sizeof(int));
	bstack->tab[0] = tmp;
	print_action("rrr");
}
