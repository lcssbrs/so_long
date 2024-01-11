/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:23:19 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/05 00:13:07 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

/*Lis tous le fichier pour en sortir sa taille*/
int	ft_read_all(char *file)
{
	int		fd;
	int		rd;
	int		len_buff;
	char	*buff;

	len_buff = 0;
	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		exit(0);
	buff = ft_calloc(sizeof(char), 1000);
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buff, 1);
		if (rd == -1)
		{
			free(buff);
			return (0);
		}
		buff[rd] = '\0';
		len_buff++;
	}
	free(buff);
	return (len_buff);
}

/*Creer une chaine de caractere de la map*/
char	*ft_read(t_data *map, int len, char *file)
{
	int		fd;
	int		rd;
	char	*buff;

	rd = 0;
	if (len == 1)
	{
		ft_printf("No map\n");
		free(map);
		exit (0);
	}
	buff = malloc(len);
	fd = open(file, O_RDONLY, 0777);
	rd = read(fd, buff, len);
	buff[rd] = '\0';
	return (buff);
}

/*Creer un tableau de chaine qui correspond a la map*/
void	ft_buff_to_map(char *buff, t_data *map)
{
	char	**carte;
	int		i;

	carte = ft_split(buff, '\n');
	i = 0;
	while (carte[i])
	{
		i++;
	}
	map->mapi = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (carte[i])
	{
		map->mapi[i] = ft_strdup(carte[i]);
		i++;
	}
	i = 0;
	while (carte[i])
	{
		free(carte[i]);
		i++;
	}
	free (carte);
	map->mapi[i] = NULL;
	map->line = i;
}

/*Mets dans une structure la taille de la map*/
void	ft_size(t_data *map)
{
	map->col = ft_strlen(map->mapi[0]);
}

void	map_init(t_data *map, char *ag)
{
	int		len;
	char	*buff;

	len = ft_read_all(ag);
	buff = ft_read(map, len, ag);
	ft_buff_to_map(buff, map);
	free(buff);
	ft_size(map);
}
