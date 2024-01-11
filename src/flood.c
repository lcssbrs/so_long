/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:25:50 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/04 21:48:12 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	f_fill(t_beg begin, t_point size, int line, int col)
{
	if (line < 0 || col < 0 || line >= size.line || col >= size.col)
		return ;
	if (begin.tab[line][col] == 'F' || begin.tab[line][col] == '1')
		return ;
	begin.tab[line][col] = 'F';
	f_fill(begin, size, line - 1, col);
	f_fill(begin, size, line + 1, col);
	f_fill(begin, size, line, col - 1);
	f_fill(begin, size, line, col + 1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

/*defini le caractere a changer*/
int	flood_fill(char **tab, t_point size, t_beg begin)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	begin.tab = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (tab[++i])
		begin.tab[i] = ft_strdup(tab[i]);
	begin.tab[i] = NULL;
	f_fill(begin, size, begin.line, begin.col);
	i = ft_check_flood(begin.tab);
	ft_free_tab(begin.tab);
	return (i);
}

//verifie si il y a un chemin possible
int	ft_check_flood(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
			{
				return (1);
			}
		}
	}
	return (0);
}
