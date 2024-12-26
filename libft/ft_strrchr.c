/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:21:01 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/10/14 14:28:05 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int i)
{
	int	len;	

	len = ft_strlen(s);
	if (i == 0)
		return ((char *)s + len);
	while (len >= 0)
	{
		if (s[len] == (char)i)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
