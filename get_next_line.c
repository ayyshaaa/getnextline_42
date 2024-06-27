/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:22:34 by aistierl          #+#    #+#             */
/*   Updated: 2024/06/27 19:03:38 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	dest = malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;
	int			read_value;
	int			index_nextline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
		return (NULL);
	// line = ft_strdup("");
	// if (line == NULL)
	// {
	// 	free(line);
	// 	return (NULL);
	// }
	// if (stash != NULL)
	// {
	// 	temp = ft_strjoin(line, buffer);
	// 	free(line);
	// 	line = temp;
	// 	if (line == NULL)
	// 	{
	// 		free(stash);
	// 		stash = NULL;
	// 		free(line);
	// 		return (NULL);
	// 	}
	// }
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	read_value = 1;
	while (read_value > 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		if (read_value == 0)
			break ;
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
		if (ft_check_newline(line, ft_strlen(line) >= 0);
			break ;
	}
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	stash = ft_substr(line, index_nextline + 1, (ft_strlen(line) - (index_nextline + 1)));
	line = ft_extract_dup(line, index_nextline);
	if (!line)
	{
		free (line);
		free (stash);
		free (buffer);
		return (NULL);
	}
	return (line);
}
