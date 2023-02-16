/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnau <mnau@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:33:41 by mnau              #+#    #+#             */
/*   Updated: 2023/02/02 20:35:27 by mnau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*tab;
	int	size;
	int	maxsize;	
}	t_stack;

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *astack, t_stack *bstack);
void	pa(t_stack *astack, t_stack *bstack);
void	pb(t_stack *astack, t_stack *bstack);
void	r_moves(t_stack *stack, char c);
void	rr_moves(t_stack *astack, t_stack *bstack);
void	revrotate(t_stack *stack, char c);
void	rrr_moves(t_stack *astack, t_stack *bstack);
void	ft_error(void);
int		ft_duplicate(t_stack *stack, int *tab);
long	ft_atol(const char *str);
int		*ft_parsing(char **split, t_stack *stack);
int		ft_size(char *split);
void	ft_reverse(int *tab, int size);
t_stack	*ft_stack(t_stack *stack, int argc, char **argv);
void	ft_tinysort(t_stack *stack);
void	ft_midsort(t_stack *astack, t_stack *bstack);
int		ft_issorted(t_stack *stack);
void	ft_check(t_stack *astack, t_stack *bstack);
void	whichmv(t_stack *a, t_stack *b);
void	ft_print_stack(t_stack *stack);
int		findchain(t_stack *a);
int		findfirstchain(t_stack *a);
void	sendtob(t_stack *a, t_stack *b);
int		find_mv_nb_a(t_stack *a, t_stack *b, int step);
int		*stockcount(t_stack *a, t_stack *b);
int		findlessmv(int *tabcount);
int		findidx_a(t_stack *a, int value);
void	do_mv(t_stack *a, t_stack *b);
int		get_max_index(t_stack *stack);
int		get_next_max(t_stack *stack, int max);
int		get_max(t_stack *stack);
int		get_next_max(t_stack *stack, int max);
void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_free_splitted(char **splitted);
void	print_action(char *action);

#endif