/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:22:34 by aistierl          #+#    #+#             */
/*   Updated: 2024/06/22 19:58:20 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
{
        char    *buffer;
        static char    *stash;
        char    *line;
        int     read_value;

        if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) < 0)
                return (NULL);
        line = NULL;
        read_value = 1;
        //1 read and add to buffer 
        read(1, buffer, BUFFER_SIZE);
        //2 move from buffer to stash and fuse with what is already there
        // 1st time 
        ft_memmove(stash, buffer, BUFFER_SIZE); 
        // next time
        ft_memove(temporary, buffer, BUFFER_SIZE);
        ft_strjoin(stash, temporary);
        //3 check for \n or \0
        ft_strcmp
        //3 move from stash to line up till \n or \0
        
        //4 return (line)
        //5 clean up stash before \n
        
        if read_value == BUFFER_SIZE
                stash = ft_memmove(buffer)
                if \n in stash
                        line = ft_memmove(line) until \n
                        return (line);
           
        
        
}