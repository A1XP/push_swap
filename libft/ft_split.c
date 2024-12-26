/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:36:45 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/26 16:27:35 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	key;
	int	count;

	count = 0;
	key = 0;
	while (*str != '\0')
	{
		if (*str != c && key == 0)
		{
			key = 1;
			count++;
		}
		else if (*str == c)
			key = 0;
		str++;
	}
	return (count);
}

static char	*copy_word(const char *str, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_result(char **result, int count)
{
	while (count > 0)
		free(result[--count]);
	free(result);
}

static char	**split_while(char **split, char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && *str == c)
			str++;
		if (*str != '\0')
		{
			split[i] = copy_word(str, c);
			if (split[i] == NULL)
			{
				free_result(split, i);
				return (NULL);
			}
			i++;
		}
		while (*str != '\0' && *str != c)
			str++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *str, char c)
{
	size_t	word_count;
	char	**split;

	if (str == NULL)
		return (NULL);
	word_count = count_words(str, c);
	split = (char **)malloc((word_count + 2) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	return (split_while(split, str, c));
}
