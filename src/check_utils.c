/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:22:01 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/04 22:29:45 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

//Verie s'il y a au moins un C

int	ft_check_collectible2(char **map)
{
	int	i;
	int	j;
	int	count_exit;

	i = 0;
	count_exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count_exit += 1;
			j++;
		}
		i++;
	}
	if (count_exit == 0)
		return (1);
	return (0);
}

int	ft_check_collectible(t_data *mlx)
{
	int	i;
	int	j;
	int	count_exit;

	i = 0;
	count_exit = 0;
	while (mlx->mapi[i])
	{
		j = 0;
		while (mlx->mapi[i][j])
		{
			if (mlx->mapi[i][j] == 'C')
				count_exit += 1;
			j++;
		}
		i++;
	}
	if (count_exit == 0)
	{
		ft_free_tab(mlx->mapi);
		free(mlx);
		ft_printf("There is no collectible\n");
		exit (1);
	}
	return (0);
}

//Verifie s'il y a une personne
int	ft_check_pers(t_data *mlx)
{
	int	i;
	int	j;
	int	count_exit;

	i = 0;
	count_exit = 0;
	while (mlx->mapi[i])
	{
		j = 0;
		while (mlx->mapi[i][j])
		{
			if (mlx->mapi[i][j] == 'P')
				count_exit += 1;
			j++;
		}
		i++;
	}
	if (count_exit != 1)
	{
		ft_free_tab(mlx->mapi);
		free(mlx);
		ft_printf("There is no character\n");
		exit (1);
	}
	return (0);
}

//Mets dans une structure les coordonees du choix
t_point	ft_valeur_point(char **map, char choisi)
{
	int		col;
	int		line;
	t_point	pers;

	line = 0;
	col = 0;
	while (map[line])
	{
		col = 0;
		while (map[line][col] && map[line][col] != choisi)
			col++;
		if (map[line][col] == choisi)
			break ;
		line++;
	}
	pers.col = col;
	pers.line = line;
	return (pers);
}
