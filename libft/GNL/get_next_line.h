/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 02:43:59 by ntordjma          #+#    #+#             */
/*   Updated: 2025/02/26 00:15:31 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE <= 0
#  error BUFFER_SIZE cannot be <= 0
# endif

# if FD_MAX < 0
#  error invalid FD
# endif

char	*get_next_line(int fd);
char	*ft_gnl_strchr(char *str, char c);
char	*ft_str_join_lines(char *s1, char *s2, int bufsize);
size_t	ft_gnl_strlcpy(char *dest, char *src, size_t l);
size_t	ft_strlen_to_charset(char *str, char c);

#endif