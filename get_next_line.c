/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:59:20 by aistierl          #+#    #+#             */
/*   Updated: 2024/07/05 18:42:10 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_concat(int fd, char *buffer, char *line)
{
	char	*temp;
	int		read_value;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));	
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
		if (read_value == 0)
			break ;
		buffer[read_value] = '\0';
		temp = ft_strjoin(line, buffer);
		if (!temp)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		free(line);
		line = temp;
		if (ft_strchr(line, 10))
			break ;
	}
	free(buffer);
	return (line);
}

char	*ft_left(char *line)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (line && line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (!line || line[i] == '\0')
		return (NULL);
	str = malloc(ft_strlen(line) - i + 1);
	if (!str)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	j = 0;
	// i++;
	while (line[i] != '\0')
		str[j++] = line[i++];
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
	{
		free(line);
		return (NULL);
	}
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
	free(line);
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
	// if (stash != NULL)
	// {
	line = ft_strjoin(line, stash);
	// 	free(stash);
	// 	stash = NULL;
	if (!line)
		return (NULL);
	// }
	// concat in line
	line = ft_read_concat(fd, buffer, line);
	if (!line)
		return (NULL);
	// extract and save in stash
	stash = ft_left(line);
	//  extract and return line
	line = ft_extract(line);
	return (line);
}
