/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:08:39 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 18:15:31 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*new_string(char *string, char	**line)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	if (string[i] == '\0')
		return (ft_free(&string));
	new = (char *)malloc((ft_strlen(string) - i + 1) * sizeof(char));
	if (new == NULL)
	{
		ft_free(&string);
		return (ft_free(line));
	}
	j = 0;
	while (string[i] != '\0')
		new[j++] = string[i++];
	new[j] = '\0';
	ft_free(&string);
	return (new);
}

char	*ft_get_line(char *string)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = string[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*read_string(int fd, char *string)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (ft_free(&string));
	read_bytes = 1;
	while (ft_strchr(string, '\n') == NULL && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			string = ft_strjoin_gnl(string, buffer);
			if (string == NULL)
				return (ft_free(&buffer));
		}
	}
	ft_free(&buffer);
	if (read_bytes < 0)
		return (ft_free(&string));
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*string;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = read_string(fd, string);
	if (string == NULL)
		return (NULL);
	line = ft_get_line(string);
	if (line == NULL)
		return (ft_free(&string));
	string = new_string(string, &line);
	return (line);
}
