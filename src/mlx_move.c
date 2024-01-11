/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:37:11 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/17 19:37:14 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	ft_move1(t_data *mlx, int *i)
{
	if (mlx->mapi[mlx->line_pers + 1][mlx->col_pers] == '1')
		return (0);
	else if (mlx->mapi[mlx->line_pers + 1][mlx->col_pers] == 'C')
		mlx->mapi[mlx->line_pers + 1][mlx->col_pers] = '0';
	else if (mlx->mapi[mlx->line_pers + 1][mlx->col_pers] == 'E')
	{
		if (ft_check_collectible2(mlx->mapi) == 1)
			ft_destroy(mlx);
	}
	*i += 1;
	ft_printf("You've done %d\n", *i);
	mlx->mapi[mlx->line_pers][mlx->col_pers] = '0';
	mlx->line_pers += 1;
	mlx_clear_window(mlx->mlx, mlx->win);
	put_image(mlx);
	return (0);
}

int	ft_move2(t_data *mlx, int *i)
{
	if (mlx->mapi[mlx->line_pers - 1][mlx->col_pers] == '1')
		return (0);
	else if (mlx->mapi[mlx->line_pers - 1][mlx->col_pers] == 'C')
		mlx->mapi[mlx->line_pers - 1][mlx->col_pers] = '0';
	else if (mlx->mapi[mlx->line_pers - 1][mlx->col_pers] == 'E')
	{
		if (ft_check_collectible2(mlx->mapi) == 1)
			ft_destroy(mlx);
	}
	*i += 1;
	ft_printf("You've done %d\n", *i);
	mlx->line_pers -= 1;
	mlx_clear_window(mlx->mlx, mlx->win);
	put_image(mlx);
	return (0);
}

int	ft_move3(t_data *mlx, int *i)
{
	if (mlx->mapi[mlx->line_pers][mlx->col_pers -1] == '1')
		return (0);
	else if (mlx->mapi[mlx->line_pers][mlx->col_pers - 1] == 'C')
	{
		mlx->mapi[mlx->line_pers][mlx->col_pers - 1] = '0';
	}
	else if (mlx->mapi[mlx->line_pers][mlx->col_pers - 1] == 'E')
	{
		if (ft_check_collectible2(mlx->mapi) == 1)
			ft_destroy(mlx);
	}
	*i += 1;
	ft_printf("You've done %d\n", *i);
	mlx->col_pers -= 1;
	mlx_clear_window(mlx->mlx, mlx->win);
	put_image(mlx);
	return (0);
}

int	ft_move4(t_data *mlx, int *i)
{
	if (mlx->mapi[mlx->line_pers][mlx->col_pers + 1] == '1')
		return (0);
	else if (mlx->mapi[mlx->line_pers][mlx->col_pers + 1] == 'C')
		mlx->mapi[mlx->line_pers][mlx->col_pers + 1] = '0';
	else if (mlx->mapi[mlx->line_pers][mlx->col_pers + 1] == 'E')
	{
		if (ft_check_collectible2(mlx->mapi) == 1)
			ft_destroy(mlx);
	}
	*i += 1;
	ft_printf("You've done %d\n", *i);
	mlx->col_pers += 1;
	mlx_clear_window(mlx->mlx, mlx->win);
	put_image(mlx);
	return (0);
}

int	on_key_press(int keysym, t_data *mlx)
{
	static int	i;

	if (keysym == XK_Escape)
		ft_destroy(mlx);
	else if (keysym == XK_s)
		ft_move1(mlx, &i);
	else if (keysym == XK_w)
		ft_move2(mlx, &i);
	else if (keysym == XK_a)
		ft_move3(mlx, &i);
	else if (keysym == XK_d)
		ft_move4(mlx, &i);
	return (0);
}
