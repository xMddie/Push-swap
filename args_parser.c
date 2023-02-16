/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:40:32 by mnau              #+#    #+#             */
/*   Updated: 2023/02/14 12:33:06 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_duplicate(t_stack *stack, int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (tab[i] == tab[j] && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_parsing(char **split, t_stack *stack)
{
	int		i;
	int		j;
	long	nb;
	int		*tab;

	i = stack->size - 1;
	j = 0;
	tab = ft_calloc(stack->size + 1, sizeof(int));
	if (!tab)
		return (0);
	while (i >= 0)
	{
		nb = ft_atol(split[j]);
		if (nb > INT_MAX || nb < INT_MIN)
			ft_error();
		tab[i] = nb;
		i--;
		j++;
	}
	if (ft_duplicate(stack, tab))
		ft_error();
	ft_reverse(tab, stack->size);
	return (tab);
}

int	ft_size_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	ft_isnum(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-')
				&& argv[i][j - 1] != ' ' && j != 0)
				return (1);
			if ((argv[i][j] == '+' || argv[i][j] == '-') && (!argv[i][j + 1]
				|| !ft_isdigit(argv[i][j + 1])))
				return (1);
			if (argv[i][j] != '+' && argv[i][j] != '-'
				&& !ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack	*ft_stack(t_stack *stack, int argc, char **argv)
{
	char	**split;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split[0] || ft_isnum(split) == 1)
			ft_error();
		stack->size = ft_size(argv[1]);
		stack->maxsize = ft_size(argv[1]);
		stack->tab = ft_parsing(split, stack);
		ft_free_splitted(split);
	}
	else
	{
		argv++;
		if (ft_isnum(argv) == 1)
			ft_error();
		stack->size = ft_size_argv(argv);
		stack->maxsize = ft_size_argv(argv);
		stack->tab = ft_parsing(argv, stack);
	}
	return (stack);
}
