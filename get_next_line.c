/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:39:26 by mparisse          #+#    #+#             */
/*   Updated: 2022/11/26 16:48:39 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cut_line(char **str)
{
	int		i;
	int		j;
	char	*ligne;
	
	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{	
		ligne =	malloc(sizeof(char) * i + 2);
		if (!ligne)
		{
			ligne =  NULL;
			(*str) = NULL;
			return ;
		}
		i++;
	}
	else
		return ;
	j = 0;
	while (j < i)
	{
		ligne[j] = (*str)[j];
		j++;
	}
	ligne[j] = 0;
	free(*str);
	(*str) = ligne;		
	// printf("ligne : %s \n", (*str));
}

void	get_buffer(char *ptr,char *ligne)
{
	int		i;
	char	*str;
	
	i = 0;
	if (ft_strchr(ligne, '\n'))
		str = ft_strchr(ligne, '\n') + 1;
	else 
		return ;
	while (str[i])
	{
		*ptr = str[i];
		i++;
		ptr++;
	}
	*ptr = 0;
	return ;
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*ligne;
	int				red;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	red = 1;
	ligne = NULL;
	// char *buffer_tmp = buffer;
	ft_strjoin(&ligne, buffer);
	while(red && !ft_strchr(buffer, '\n'))
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red < 0)
			return (NULL);
		if (red == 0)
		{
			// printf("buffer : %s \n", buffer);
			// buffer[0] = 0;
			break ;
		}
		buffer[red] = 0;
		if (!ligne)
			ligne = ft_strdup(buffer);
		else
			ft_strjoin(&ligne, buffer);
		// if (ft_strchr(buffer, '\n') != NULL)
		// 	break ;
	}
	if (ft_strchr(ligne, '\n'))
		get_buffer(buffer,ligne);
	else
		return (ligne);
	// get_buffer(buffer ,ligne);
	cut_line(&ligne);
	return (ligne);
}
/*
si je croise un backslash 0 pendant la lecture je retourne la valeur et je set
le
// */
int main()
{
	char *str;
	int fd;
	
	fd = open("b", O_RDONLY);
	if (fd < 0)
	{
		printf("pas ok");
		return (0);
	}
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	free(str);
	str = get_next_line(fd);
	// printf("%s", str);
	free(str);
	
	str = get_next_line(fd);
	// printf("%s", str);
	free(str);
	
	str = get_next_line(fd);
	// printf("%s", str);
	free(str);

	str = get_next_line(fd);
	// printf("%s", str);
	free(str);
	
	str = get_next_line(fd);
	printf("%s", str);
	free(str);

	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);

	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
}
