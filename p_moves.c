/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:27:48 by mnau              #+#    #+#             */
/*   Updated: 2023/02/02 15:03:50 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *astack, t_stack *bstack)
{
	int	tmp;

	if (bstack->size == 0)
		return ;
	tmp = bstack->tab[0];
	astack->size = astack->size + 1;
	bstack->size = bstack->size - 1;
	ft_memmove(astack->tab + 1, astack->tab, astack->size * sizeof(int));
	ft_memmove(bstack->tab, bstack->tab + 1, bstack->size * sizeof(int));
	astack->tab[0] = tmp;
	print_action("pa");
}

void	pb(t_stack *astack, t_stack *bstack)
{
	int	tmp;

	if (astack->size == 0)
		return ;
	bstack->size = bstack->size + 1;
	astack->size = astack->size - 1;
	tmp = astack->tab[0];
	ft_memmove(bstack->tab + 1, bstack->tab, bstack->size * sizeof(int));
	ft_memmove(astack->tab, astack->tab + 1, astack->size * sizeof(int));
	bstack->tab[0] = tmp;
	print_action("pb");
}
