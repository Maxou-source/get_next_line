/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:49:03 by mparisse          #+#    #+#             */
/*   Updated: 2022/11/26 15:29:34 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

char    *ft_strdup(char *s);
void	ft_strjoin(char **s1, char *s2);
size_t 	ft_strlen(char const *s);
char	*ft_strchr(char *s, int c);
char    *get_next_line(int fd);
