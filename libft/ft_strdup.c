/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:09:34 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/10/14 15:42:54 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*dst;

	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	dst = (char *)malloc(len * sizeof(char) + 1);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s, len);
	dst[len] = '\0';
	return (dst);
}
