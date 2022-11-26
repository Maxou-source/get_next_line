/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:53:07 by mparisse          #+#    #+#             */
/*   Updated: 2022/11/26 15:10:06 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	// free((char *)s);
	return (str);
}

void	ft_strjoin(char **s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		lens1;
	size_t		lens2;

	if (!*s1)
	{
		free(*s1);
		*s1 = ft_strdup(s2);
		// printf("s1 = %s \n", *s1);
		return ;
	}
	// printf("\n%s | %p\n", *s1, &(*s1));
	lens1 = ft_strlen(*s1);
	lens2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
	{
		free(str);
		return ;
	}
	i = 0;
	while ((*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[lens1 + i] = s2[i];
		i++;
	}
	str[lens1 + i] = 0;
	free(*s1);
	(*s1) = str;
	return ;
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (s + i);
	return (NULL);
}
