/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:50:52 by mnau              #+#    #+#             */
/*   Updated: 2023/02/02 13:15:01 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->tab[i] < stack->tab[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	get_max_index(t_stack *stack)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = stack->tab[0];
	while (i < stack->size)
	{
		if (max < stack->tab[i])
		{
			max = stack->tab[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->tab[0];
	while (i < stack->size)
	{
		if (max < stack->tab[i])
		{
			max = stack->tab[i];
		}
		i++;
	}
	return (max);
}

int	get_next_max(t_stack *stack, int max)
{
	int	i;
	int	j;
	int	next_max;

	i = -1;
	j = 0;
	next_max = INT_MAX;
	if (max > get_max(stack))
	{
		j = get_max_index(stack) + 1;
		if (j >= stack->size)
			j = 0;
	}
	else
	{
		while (++i < stack->size)
		{
			if (stack->tab[i] > max && stack->tab[i] < next_max)
			{
				next_max = stack->tab[i];
				j = i;
			}
		}
	}
	return (j);
}

int	findchain(t_stack *a)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (i < a->size)
	{
		if (a->tab[i] < a->tab[i + 1])
			j++;
		else
		{
			if (res < j)
				res = j;
			j = 0;
		}
		i++;
	}
	return (res + 1);
}
