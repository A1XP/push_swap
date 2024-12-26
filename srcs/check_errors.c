/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:57:32 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/26 17:17:20 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_error(t_node *a, int num)
{
	if (a == NULL)
		return (0);
	while (a != NULL)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

int	number_error(char *str)
{
	int	i;

	if (!(str[0] == '+' || str[0] == '-' || (str[0] >= '0' && str[0] <= '9')))
		return (1);
	if ((str[0] == '+' || str[0] == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	i = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_nodes(t_node **nodes)
{
	t_node	*tmp;
	t_node	*current;

	if (nodes == NULL)
		return ;
	current = *nodes;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*nodes = NULL;
}

void	error_free(t_node **a, int argc, char **argv)
{
	free_nodes(a);
	if (argc == 2)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}
