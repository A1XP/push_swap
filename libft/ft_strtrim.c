/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:21:16 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/10/11 16:25:04 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && s1[end - 1] != '\0' && ft_strchr(set, s1[end - 1]))
		end--;
	str = (char *)malloc(end - start + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		str[i] = s1[start + i];
		i++;
	}
	str[end - start] = '\0';
	return (str);
}
