/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:39:13 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 19:04:09 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *nodes)
{
	if (nodes == NULL)
		return (0);
	while (nodes->next)
	{
		if (nodes->value > nodes->next->value)
			return (0);
		nodes = nodes->next;
	}
	return (1);
}

void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b, 1);
	set_cheapest(*a);
	set_cheapest(*b);
}

void	reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b, 1);
	set_cheapest(*a);
	set_cheapest(*b);
}

void	finish_rotation(t_node **nodes, t_node *top, char stack_name)
{
	while (*nodes != top)
	{
		if (stack_name == 'a')
		{
			if (top->middle == 0)
				ra(nodes, 1);
			else
				rra(nodes, 1);
		}
		else if (stack_name == 'b')
		{
			if (top->middle == 0)
				rb(nodes, 1);
			else
				rrb(nodes, 1);
		}
	}
}
