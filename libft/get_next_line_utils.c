/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:55:19 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 11:50:33 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tab;
	char	*p;
	int		i;

	i = 0;
	tab = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	p = tab;
	while (s1 && *s1)
	{
		*tab++ = *s1++;
		i++;
	}
	free(s1 - i);
	i = 0;
	while (s2 && *s2)
	{
		*tab++ = *s2++;
		i++;
	}
	*tab = '\0';
	return (p);
}

int	check(char **s, int i)
{
	char		c;
	char		*ss;

	ss = *s;
	c = *(ss + i);
	*s += i;
	if (c == '\n')
		return (1);
	return (0);
}

char	*norme_fun(int i, char *s)
{
	char	*tab;

	if (s && *s && check(&s, i))
	{
		s++;
		tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!tab)
			return (NULL);
		ft_strlcpy(tab, s, ft_strlen(s) + 1);
		free(s - i - 1);
		return (tab);
	}
	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s, ft_strlen(s) + 1);
	if (s)
		free(s - i);
	return (tab);
}
