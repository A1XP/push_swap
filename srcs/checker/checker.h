/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkhvorov <pkhvorov@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:16:38 by pkhvorov          #+#    #+#             */
/*   Updated: 2024/11/29 18:44:28 by pkhvorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "../includes/push_swap.h"
# include "../libft/libft.h"
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*read_string(int fd, char *string);
char	*ft_get_line(char *string);
char	*new_string(char *string, char	**line);

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_free(char **str);

#endif
