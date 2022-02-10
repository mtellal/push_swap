/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:09:29 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 14:46:22 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_line(char *s)
{
	while (s && *s)
	{
		if (*s++ == '\n')
			return (1);
	}
	return (0);
}

char	*ft_findline(char *s)
{
	int		i;
	char	*tab;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	tab = malloc(sizeof(char) * (i + 1));
	if (!tab)
	{
		if (s)
			free(s);
		return (NULL);
	}
	ft_strlcpy(tab, s, i + 1);
	return (tab);
}

char	*ft_resize(char *s, char *line)
{
	int		i;

	if (!line)
		return (NULL);
	i = ft_strlen(line);
	return (norme_fun(i, s));
}

int	gnl(char **s, char **line, int *j)
{
	*s = ft_resize(*s, *line);
	if (!*s || !*line)
		return (-1);
	if (*j == 0 && (ft_strlen(*s) == 0))
	{
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*s;
	char		*buffer;
	int			j;

	j = 1;
	if (fd < 0 || read(fd, NULL, 0) < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	while (!ft_line(s) && j > 0)
	{
		j = read(fd, buffer, BUFFER_SIZE);
		if (j)
		{
			buffer[j] = '\0';
			s = ft_strjoin_free(s, buffer);
		}
	}
	free(buffer);
	*line = ft_findline(s);
	return (gnl(&s, line, &j));
}
