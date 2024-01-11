/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:33:29 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/17 19:33:34 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_put_img(t_data *mlx, int i, int j)
{
	while (mlx->mapi[i])
	{
		j = 0;
		while (mlx->mapi[i][j])
		{
			mlx_put_image_to_window(mlx->mlx, mlx->win, \
			mlx->img_back, j * PIXEL, i * PIXEL);
			j++;
		}
		i++;
	}
}

void	ft_put_img1(t_data *mlx, int i, int j)
{
	while (mlx->mapi[i])
	{
		j = 0;
		while (mlx->mapi[i][j])
		{
			if (mlx->mapi[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, \
				mlx->win, mlx->img_coin, j * PIXEL, i * PIXEL);
			j++;
		}
		i++;
	}
}

void	put_image(t_data *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_put_img(mlx, i, j);
	i = 0;
	mlx_put_image_to_window(mlx->mlx, mlx->win, \
	mlx->img_exit, (mlx->col_exit * PIXEL), (mlx->line_exit * PIXEL));
	mlx_put_image_to_window(mlx->mlx, \
	mlx->win, mlx->img_char, (mlx->col_pers * PIXEL), (mlx->line_pers * PIXEL));
	ft_put_img1(mlx, i, j);
	i = 0;
	while (mlx->mapi[i])
	{
		j = 0;
		while (mlx->mapi[i][j])
		{
			if (mlx->mapi[i][j] == '1')
				mlx_put_image_to_window \
				(mlx->mlx, mlx->win, mlx->img_wall, j * PIXEL, i * PIXEL);
			j++;
		}
		i++;
	}
}

void	ft_free(t_data *mlx)
{
	int	i;

	i = 0;
	while (mlx->mapi[i])
	{
		free(mlx->mapi[i]);
		i++;
	}
	free(mlx->mapi);
	free (mlx);
}

void	ft_destroy(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img_back);
	mlx_destroy_image(mlx->mlx, mlx->img_char);
	mlx_destroy_image(mlx->mlx, mlx->img_coin);
	mlx_destroy_image(mlx->mlx, mlx->img_wall);
	mlx_destroy_image(mlx->mlx, mlx->img_exit);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	mlx_loop_end(mlx->mlx);
	free(mlx->mlx);
	ft_free(mlx);
	exit(0);
}
