/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:43:46 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 19:02:41 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_node **a)
{
	t_node	*biggest;

	biggest = find_biggest(*a);
	if (*a == biggest)
		ra(a, 1);
	else if ((*a)->next == biggest)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}

static void	move_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->middle == 0 && cheapest->target->middle == 0)
		rotate_both(a, b, cheapest);
	else if (cheapest->middle == 1 && cheapest->target->middle == 1)
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target, 'a');
	pa(a, b, 1);
}

static void	push_swap_while(t_node **a, t_node **b)
{
	int		count_a;
	int		index;

	index = index_stack(a);
	count_a = nodes_count(*a);
	while (count_a-- > 3)
	{
		if ((*a)->index < index / 2)
		{
			pb(b, a, 1);
			rb(b, 1);
		}
		else
			pb(b, a, 1);
	}
}

void	push_swap(t_node **a, t_node **b)
{
	t_node	*smallest;

	push_swap_while(a, b);
	sort3(a);
	while (*b)
	{
		nodes_init(*a, *b);
		move_nodes(a, b);
	}
	set_position(*a);
	smallest = find_smallest(*a);
	if (smallest->middle == 0)
		while (*a != smallest)
			ra(a, 1);
	else
		while (*a != smallest)
			rra(a, 1);
}
