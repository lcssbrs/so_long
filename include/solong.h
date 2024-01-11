/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiberr <lseiberr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:08:40 by lseiberr          #+#    #+#             */
/*   Updated: 2023/09/05 01:34:22 by lseiberr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../Get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"

# define PIXEL 50
# define PIXEL1 500

typedef struct s_point
{
	int	col;
	int	line;
}	t_point;

typedef struct s_beg
{
	int		col;
	int		line;
	char	**tab;
}	t_beg;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		col_pers;
	int		line_pers;
	int		col_exit;
	int		line_exit;
	void	*img_wall;
	void	*img_coin;
	void	*img_exit;
	void	*img_char;
	void	*img_back;
	char	**mapi;
	int		col;
	int		line;
}	t_data;

//Functions use to check
int		ft_check_exit(t_data *mlx);
void	ft_check_map_value(t_data *mlx);
int		ft_check_map_rect(t_data *mlx);
int		ft_check_arg(int ac);
int		ft_check_pers(t_data *mlx);
int		ft_check_collectible(t_data *mlx);
int		ft_check_collectible2(char **map);
void	ft_check_all(t_data *mlx);
void	ft_exit(t_data *mlx);
void	ft_check_value(t_data *mlx);
void	ft_check_first(char *ag);

//Functions to read map
void	ft_buff_to_map(char *buff, t_data *map);
char	*ft_read(t_data *map, int len, char *file);
int		ft_read_all(char *file);
t_point	ft_valeur_point(char **map, char choisi);
void	ft_size(t_data *map);
void	map_init(t_data *map, char *ag);

//Functions flood
int		ft_check_flood(char **map);
int		flood_fill(char **tab, t_point size, t_beg begin);
void	f_fill(t_beg begin, t_point size, int line, int col);

//Functions mlx init
void	init_window(t_data *mlx);
void	ft_free_tab(char **tab);
void	initialise_image(t_data *mlx);
void	ft_put_img(t_data *mlx, int i, int j);
void	valeur_point(t_data *mlx);
void	ft_put_img1(t_data *mlx, int i, int j);
void	ft_free(t_data *mlx);
void	ft_destroy(t_data *mlx);
void	put_image(t_data *mlx);

//Functions move
int		ft_move1(t_data *mlx, int *i);
int		ft_move2(t_data *mlx, int *i);
int		ft_move3(t_data *mlx, int *i);
int		ft_move4(t_data *mlx, int *i);
int		on_key_press(int keysym, t_data *mlx);

#endif
