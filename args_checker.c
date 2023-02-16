/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:33:30 by mnau              #+#    #+#             */
/*   Updated: 2023/02/02 14:07:58 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(t_stack *astack, t_stack *bstack)
{
	if (ft_issorted(astack))
		return ;
	if (astack->size == 2 || astack->size == 3)
		ft_tinysort(astack);
	else if (astack->size >= 4 && astack->size < 10)
		ft_midsort(astack, bstack);
	else
	{
		sendtob(astack, bstack);
		while (bstack->size)
			do_mv(astack, bstack);
	}
	print_action("");
}
