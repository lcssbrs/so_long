/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:49:15 by lseiberr          #+#    #+#             */
/*   Updated: 2023/05/11 17:07:20 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ouvrir un fichier texte
//recuperer la taille du buffer
//si la taille du buffer est plus grande qu'une ligne return la ligne
//sinon boucler le buffer jusqu'a trouver une ligne puis return la ligne
//pouvoir le faire en boucle jusqu'a la fin du fichier

//il faut manipuler un fichier
//recuperer les infos qu'il y a dedans
// gerer les variables statiques pour que le programme
// n'oublie pas ou il en est des qu'il se ferme

#include "get_next_line.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
