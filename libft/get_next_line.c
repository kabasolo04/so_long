/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:35:45 by kabasolo          #+#    #+#             */
/*   Updated: 2024/02/02 16:49:39 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lfc(char *str, char c) // lfc -> Lenght For Char
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (str[l] != '\0')
		l ++;
	while (i <= l)
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i ++;
	}
	return (-1);
}

static char	*ft_join(char *line, char *buffer)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (line);
	s = malloc((ft_lfc(line, '\0') + ft_lfc(buffer, '\0') + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		s[i] = line[i];
		i ++;
	}
	j = 0;
	while (buffer[j - 1] != '\n' && buffer[j] != '\0')
	{
		s[i + j] = buffer[j];
		j ++;
	}
	s[i + j] = '\0';
	free(line);
	return (s);
}

static void	ft_cut_buffer(char *buffer)
{
	int	i;
	int	t;

	i = 0;
	t = ft_lfc(buffer, '\n');
	while (buffer[i + t] != '\0')
	{
		buffer[i] = buffer[i + t + 1];
		i ++;
	}
	while (i <= BUFFER_SIZE)
		buffer[i ++] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			rbytes;

	rbytes = 1;
	line = (char *)malloc(sizeof(char) * 1);
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (free(line), NULL);
	line[0] = '\0';
	line = ft_join(line, buffer);
	while (ft_lfc(line, '\n') < 0 && rbytes > 0)
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes == -1)
			return (free(line), ft_bzero(buffer, ft_lfc(buffer, '\0')), NULL);
		buffer[rbytes] = '\0';
		line = ft_join(line, buffer);
	}
	if (line[0] == '\0')
		return (free(line), NULL);
	return (ft_cut_buffer(buffer), line);
}
