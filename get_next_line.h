/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:22:41 by aistierl          #+#    #+#             */
/*   Updated: 2024/06/27 19:03:44 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_check_newline(char *str, int len);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_extract_dup(char *str, int len);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s);

#endif