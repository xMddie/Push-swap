/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:25:22 by mnau              #+#    #+#             */
/*   Updated: 2023/02/02 15:04:18 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->tab[0];
	stack->tab[0] = stack->tab[1];
	stack->tab[1] = tmp;
}

void	sa(t_stack *stack)
{
	ft_swap(stack);
	print_action("sa");
}

void	sb(t_stack *stack)
{
	ft_swap(stack);
	print_action("sb");
}

void	ss(t_stack *astack, t_stack *bstack)
{
	ft_swap(astack);
	ft_swap(bstack);
}
