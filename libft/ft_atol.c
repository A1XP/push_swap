/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:12:03 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/26 16:00:07 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	number;
	int		i;
	int		sign;

	number = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] != '\0' && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10;
		number = number + str[i] - 48;
		i++;
	}
	return (sign * number);
}
