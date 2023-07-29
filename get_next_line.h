/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:53:28 by bsalgado          #+#    #+#             */
/*   Updated: 2023/07/29 15:53:30 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_mod(char *s1, char *s2);
size_t	ft_strclen(const char *s, char c);
char	*ft_substr_line(char *s);
char	*ft_memmove_mod(char *str);

#endif