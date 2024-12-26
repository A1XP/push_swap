/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:20:01 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/12/03 13:31:17 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_both(t_node **a, t_node **b)
{
	free_nodes(a);
	free_nodes(b);
}

static void	error(t_node **a, t_node **b, char *command)
{
	free_nodes(a);
	free_nodes(b);
	free(command);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_command(t_node **a, t_node **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, 0);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, 0);
	else
		error(a, b, command);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*next_line;
	int		count;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	get_nodes(&a, argc, argv);
	count = nodes_count(a);
	next_line = get_next_line(0);
	while (next_line)
	{
		parse_command(&a, &b, next_line);
		free(next_line);
		next_line = get_next_line(0);
	}
	if (is_sorted(a) && nodes_count(a) == count)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_both(&a, &b);
}
