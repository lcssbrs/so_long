/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:20:17 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/06 11:38:45 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

//check s'il y a le bon nombre d'args
int	ft_check_arg(int ac)
{
	if (ac > 2)
	{
		ft_printf("Too many arguments, please enter only the map\n");
		exit (1);
	}
	if (ac < 2)
	{
		ft_printf("Too few arguments, please enter the missing map\n");
		exit (1);
	}
	return (0);
}

//check si la map est bien rectangle
int	ft_check_map_rect(t_data *mlx)
{
	int	i;

	i = 0;
	if (!mlx->mapi)
	{
		ft_free_tab(mlx->mapi);
		free(mlx);
		ft_printf("Map is empty\n");
		exit (1);
	}
	while (mlx->mapi[i])
		i++;
	i -= 1;
	while (i > 0)
	{
		if (ft_strlen(mlx->mapi[i]) != ft_strlen(mlx->mapi[i - 1]))
		{
			ft_free_tab(mlx->mapi);
			free(mlx);
			ft_printf("The map is not a rectangle\n");
			exit (1);
		}
		i--;
	}
	return (0);
}

//check si les contours de la map sont bien des 1
void	ft_check_map_value(t_data *mlx)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (mlx->mapi[0][++i])
	{
		if (mlx->mapi[0][i] != '1')
			ft_exit(mlx);
	}
	i = 0;
	while (mlx->mapi[i])
		i++;
	i -= 1;
	while (mlx->mapi[i][++j])
	{
		if (mlx->mapi[i][j] != '1')
			ft_exit(mlx);
	}
	while (--i > 0)
	{
		if (mlx->mapi[i][0] != '1' || \
		mlx->mapi[i][ft_strlen(mlx->mapi[i]) - 1] != '1')
			ft_exit(mlx);
	}
}

//verifie s'il y a une sortie
int	ft_check_exit(t_data *mlx)
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
			if (mlx->mapi[i][j] == 'E')
				count_exit += 1;
			j++;
		}
		i++;
	}
	if (count_exit != 1)
	{
		ft_free_tab(mlx->mapi);
		free(mlx);
		ft_printf("There is no exit\n");
		exit (1);
	}
	return (0);
}

void	ft_check_value(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->mapi[i])
	{
		j = 0;
		while (mlx->mapi[i][j])
		{
			if (mlx->mapi[i][j] != '1' && mlx->mapi[i][j] != '0' \
			&& mlx->mapi[i][j] != 'E' && mlx->mapi[i][j] != 'C' \
			&& mlx->mapi[i][j] != 'P')
			{
				ft_free_tab(mlx->mapi);
				free(mlx);
				ft_printf("There is a character that shouldn't be there\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
