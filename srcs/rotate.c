/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:55:55 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 19:01:54 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **nodes)
{
	t_node	*last;
	int		count;

	count = nodes_count(*nodes);
	if (*nodes == NULL || nodes == NULL || count == 1)
		return ;
	last = find_last(*nodes);
	last->next = *nodes;
	*nodes = (*nodes)->next;
	(*nodes)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}

void	ra(t_node **a, int p)
{
	rotate(a);
	if (p == 1)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int p)
{
	rotate(b);
	if (p == 1)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b, int p)
{
	rotate(a);
	rotate(b);
	if (p == 1)
		write(1, "rr\n", 3);
}
