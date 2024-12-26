/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:29:04 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/10/11 17:39:20 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	ls1;
	size_t	ls2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	str = (char *)malloc((ls1 + ls2) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, ls1);
	ft_memcpy(str + ls1, s2, ls2);
	str[ls1 + ls2] = '\0';
	return (str);
}
