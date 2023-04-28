/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akakinad <akakinad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:45:45 by akakinad          #+#    #+#             */
/*   Updated: 2023/03/07 13:45:48 by akakinad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_free(char **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

static void	rest(char **save, char **line)
{
	char	*tmp;
	size_t	index;

	index = 0;
	while ((*save)[index] && (*save)[index] != '\n')
		index++;
	if ((*save)[index] == '\n')
	{
		tmp = *save;
		*line = ft_substr(tmp, 0, index + 1);
		*save = ft_strdup(&(*save)[index + 1]);
		ft_free(&tmp);
	}
	else
	{
		*line = ft_strdup(*save);
		ft_free(save);
		*save = NULL;
	}
	if (**line == '\0')
		ft_free(line);
}

static void	get_line(int fd, char **save, char *buffer, char **line)
{
	ssize_t	endof;
	char	*tmp;

	endof = 1;
	buffer[0] = '\0';
	while (endof != 0 && !(ft_strchr(buffer, '\n')))
	{
		endof = read(fd, buffer, BUFFER_SIZE);
		buffer[endof] = '\0';
		tmp = *save;
		*save = ft_strjoin(tmp, buffer);
		ft_free(&tmp);
	}
	ft_free(&buffer);
	rest(save, line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) == -1)
	{
		ft_free(&buffer);
		return (NULL);
	}
	if (!save)
		save = ft_strdup("");
	get_line(fd, &save, buffer, &line);
	return (line);
}
