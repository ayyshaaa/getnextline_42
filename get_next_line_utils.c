/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:22:43 by aistierl          #+#    #+#             */
/*   Updated: 2024/07/08 16:55:51 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*result;
	int				character;

	result = (char *)s;
	character = c % 256;
	i = 0;
	while (s && s[i] != '\0')
	{
		if (result[i] == character)
			return (result + i);
		i++;
	}
	return (NULL);
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	unsigned char	*temporary;
// 	unsigned int	i;

// 	if (nmemb != 0 && (size > 4294967295 / nmemb))
// 		return (NULL);
// 	temporary = malloc(sizeof(char) * (nmemb * size));
// 	if (temporary == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < (nmemb * size))
// 	{
// 		temporary[i] = '\0';
// 		i++;
// 	}
// 	return (temporary);
// }
