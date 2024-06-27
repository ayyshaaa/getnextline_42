/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:22:43 by aistierl          #+#    #+#             */
/*   Updated: 2024/06/27 19:03:41 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
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
	else
	{
		i = 0;
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
		{
			new[i + j] = s2[j];
			j++;
		}
		new[i + j] = '\0';
		return (new);
	}
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char				*sub;
	unsigned int		i;

	if (ft_strlen(s) < start || len == 0)
		return (ft_strdup(s + ft_strlen(s)));
	if ((ft_strlen(s) - 1) == start || ft_strlen(s + start) < len)
		return (ft_strdup(s + start));
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
int	ft_check_newline(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_extract_dup(char *str, int limit)
{
	char	*dest;
	int		i;

	if (!str)
		return (NULL);
	dest = malloc(limit + 2);
	if (dest == NULL)
	{
		free (dest);
		return (NULL);
	}
	i = 0;
	while (i < limit)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\n';
	dest[++i] = '\0';
	return (dest);
}

