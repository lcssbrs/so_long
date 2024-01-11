/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:13:23 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/05 00:16:34 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	main(int ac, char **ag)
{
	t_data	*mlx;
	t_point	size;
	t_beg	begin;

	ft_check_arg(ac);
	ft_check_first(ag[1]);
	mlx = malloc(sizeof(t_data));
	map_init(mlx, ag[1]);
	size = ft_valeur_point(mlx->mapi, 'P');
	begin.col = size.col;
	begin.line = size.line;
	ft_size(mlx);
	size.col = mlx->col;
	size.line = mlx->line;
	ft_check_all(mlx);
	if (flood_fill(mlx->mapi, size, begin) == 1)
	{
		ft_free_tab(mlx->mapi);
		free(mlx);
		ft_printf("No way possible\n");
		exit(1);
	}
	init_window(mlx);
	ft_printf("ok\n");
}
