/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:59:46 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/05 01:35:56 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	initialise_image(t_data *mlx)
{
	int	img_width;
	int	img_height;

	mlx->img_char = \
	mlx_xpm_file_to_image(mlx->mlx, "xlm/tom.xpm", &img_width, &img_height);
	mlx->img_wall = \
	mlx_xpm_file_to_image(mlx->mlx, "xlm/wall3.xpm", &img_width, &img_height);
	mlx->img_coin = \
	mlx_xpm_file_to_image(mlx->mlx, "xlm/trap2.xpm", &img_width, &img_height);
	mlx->img_exit = \
	mlx_xpm_file_to_image(mlx->mlx, "xlm/jerry.xpm", &img_width, &img_height);
	mlx->img_back = \
	mlx_xpm_file_to_image(mlx->mlx, "xlm/fond2.xpm", &img_width, &img_height);
}

void	valeur_point(t_data *mlx)
{
	t_point	pers;

	pers = ft_valeur_point(mlx->mapi, 'P');
	mlx->col_pers = pers.col;
	mlx->line_pers = pers.line;
	pers = ft_valeur_point(mlx->mapi, 'E');
	mlx->col_exit = pers.col;
	mlx->line_exit = pers.line;
}

int	on_window_close(t_data *mlx)
{
	ft_destroy(mlx);
	return (0);
}

void	init_window(t_data *mlx)
{
	valeur_point(mlx);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->col * PIXEL, \
	(mlx->line) * PIXEL, "Pacman en moins bien");
	initialise_image(mlx);
	put_image(mlx);
	mlx_key_hook(mlx->win, on_key_press, mlx);
	mlx_hook(mlx->win, DestroyNotify, \
	StructureNotifyMask, on_window_close, mlx);
	mlx_do_sync(mlx->mlx);
	mlx_loop(mlx->mlx);
}
