/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:16:49 by mtellal           #+#    #+#             */
/*   Updated: 2022/01/07 11:38:47 by mtellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int			get_next_line(int fd, char **line);
char		*ft_strjoin_free(char *s1, char *s2);
size_t		ft_strlen(char *s);
char		*ft_strlcpy(char *s, char *s1, size_t i);
char		*norme_fun( int i, char *s);

#endif
