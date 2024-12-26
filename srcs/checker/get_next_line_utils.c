/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:22:58 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 13:11:13 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (s1 == NULL)
		i = ft_strlen(s2);
	else
		i = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (ft_free(&s1));
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	ft_free (&s1);
	return (str);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
