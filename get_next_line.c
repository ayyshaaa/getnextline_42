/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:59:20 by aistierl          #+#    #+#             */
/*   Updated: 2024/07/01 19:58:12 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_concat(int fd, char *buffer, char *line)
{
	char	*temp;
	int		read_value;

	read_value = 1;
	while (read_value > 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[read_value] = '\0';
		if (read_value == 0)
			break ;
		temp = ft_strjoin(line, buffer);
		if (!temp)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		free(line);
		line = temp;
		if (ft_strchr(line, 10))
			break ;
	}
	return (line);
}

char	*ft_left(char *line)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (line && line[i] != '\n' && line[i] != '\0')
		i++;
	if (!line || line[i] == '\0')
		return (NULL);
	i++;
	str = malloc(ft_strlen(line) - i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (line && line[i + j] != '\0')
	{
		str[j] = line[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_extract(char *line)
{
	char	*cropped;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	cropped = malloc(i + 2);
	if (cropped == NULL)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		cropped[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		cropped[i] = '\n';
		i++;
	}
	cropped[i] = '\0';
	return (cropped);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
		return (NULL);
	line = NULL;
	// check if stash empty, if no, apend to line
	if (stash)
	{
		line = ft_strjoin("", stash);
		free(stash);
		stash = NULL;
		if (!line)
			return (NULL);
	}
	//buffer
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		if(!line)
			free(line);
		return (NULL);
	}
	// concat in line
	line = ft_read_concat(fd, buffer, line);
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	// extract and save in stash
	stash = ft_left(line);
	//  extract and return line
	line = ft_extract(line);
	return (line);
}
