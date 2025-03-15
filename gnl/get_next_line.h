/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaamaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:27:39 by anaamaja          #+#    #+#             */
/*   Updated: 2024/12/26 13:26:05 by anaamaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char                            *get_next_line(int fd);
size_t                          ft_strlen_gnl(const char *str);
char                            *ft_strdup_gnl(const char *s1);
char                            *ft_strjoin_gnl(char *s1, const char *s2);
char                            *ft_substr_gnl(char const *s, unsigned int start,
                                                size_t len);
char                            *ft_strchr_gnl(char *str, char search_str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#endif
