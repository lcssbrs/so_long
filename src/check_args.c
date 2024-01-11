/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:42:21 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/17 19:42:23 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_check_all(t_data *mlx)
{
	ft_check_exit(mlx);
	ft_check_map_value(mlx);
	ft_check_map_rect(mlx);
	ft_check_pers(mlx);
	ft_check_value(mlx);
	ft_check_collectible(mlx);
}

void	ft_exit(t_data *mlx)
{
	ft_free_tab(mlx->mapi);
	free(mlx);
	ft_printf("The map is not surrounded by the 1 character\n");
	exit (1);
}

void	ft_check_first(char *ag)
{
	int	i;

	i = open(ag, O_RDONLY, 0777);
	if (i == -1)
	{
		ft_printf("File can't be opened\n");
		exit(1);
	}
	else
		close(i);
	i = 0;
	while (ag[i])
		i++;
	i -= 1;
	if (ag[i] != 'r' || ag[i - 1] != 'e' || \
	ag[i - 2] != 'b' || ag[i - 3] != '.')
	{
		ft_printf("Not a file .ber\n");
		exit(1);
	}
}
