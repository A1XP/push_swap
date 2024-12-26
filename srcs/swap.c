/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:37:53 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 19:03:25 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **nodes)
{
	int	count;

	count = nodes_count(*nodes);
	if (*nodes == NULL || nodes == NULL || count == 1)
		return ;
	*nodes = (*nodes)->next;
	(*nodes)->previous->previous = *nodes;
	(*nodes)->previous->next = (*nodes)->next;
	if ((*nodes)->next)
		(*nodes)->next->previous = (*nodes)->previous;
	(*nodes)->next = (*nodes)->previous;
	(*nodes)->previous = NULL;
}

void	sa(t_node **a, int p)
{
	swap(a);
	if (p == 1)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int p)
{
	swap(b);
	if (p == 1)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, int p)
{
	swap(a);
	swap(b);
	if (p == 1)
		write(1, "ss\n", 3);
}
