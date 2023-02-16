/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:57:22 by mnau              #+#    #+#             */
/*   Updated: 2023/02/02 14:22:13 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

static void	display_action(char *action)
{
	ft_putstr_fd(action, 1);
	ft_putchar_fd('\n', 1);
}

void	print_action(char *action)
{
	static char	*last_action;

	if (!last_action)
		last_action = ft_strdup(action);
	else
	{
		if ((!ft_strcmp(last_action, "sa") && !ft_strcmp(action, "sb"))
			|| (!ft_strcmp(last_action, "sb") && !ft_strcmp(action, "sa")))
			ft_putstr_fd("ss\n", 1);
		else if ((!ft_strcmp(last_action, "ra") && !ft_strcmp(action, "rb"))
			|| (!ft_strcmp(last_action, "rb") && !ft_strcmp(action, "ra")))
			ft_putstr_fd("rr\n", 1);
		else if ((!ft_strcmp(last_action, "rra") && !ft_strcmp(action, "rrb"))
			|| (!ft_strcmp(last_action, "rrb") && !ft_strcmp(action, "rra")))
			ft_putstr_fd("rrr\n", 1);
		else
		{
			display_action(last_action);
			if (ft_strcmp(action, ""))
				display_action(action);
		}
		free(last_action);
		last_action = NULL;
	}
}
