/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:04:11 by mnau              #+#    #+#             */
/*   Updated: 2023/02/14 12:30:07 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*bstack;

	if (argc == 1)
		return (0);
	if (argv[1][0] == '\0')
		ft_error();
	stack = ft_calloc(1, sizeof(t_stack));
	bstack = ft_calloc(1, sizeof(t_stack));
	if (!stack || !bstack)
		return (1);
	stack = ft_stack(stack, argc, argv);
	bstack->tab = ft_calloc(stack->size + 1, sizeof(int));
	if (!bstack->tab)
		return (1);
	bstack->size = 0;
	ft_check(stack, bstack);
	ft_free_stacks(stack, bstack);
}
