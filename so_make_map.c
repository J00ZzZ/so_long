/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:15:06 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/18 15:50:24 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ct_c(t_program *prog)
{
	int	y;
	int	x;

	y = 0;
	while (prog->map[y])
	{
		x = 0;
		while (prog->map[y][x])
		{
			if (prog->map[y][x] == 'C')
			{
				prog->collect++;
			}
			x++;
		}
		y++;
	}
}

void	ft_to_p(t_program *prog)
{
	int	y;
	int	x;

	y = 0;
	while (prog->map[y])
	{
		x = 0;
		while (prog->map[y][x])
		{
			if (prog->map[y][x] == 'P')
			{
				prog->x_p = x * 50;
				prog->y_p = y * 50;
			}
			x++;
		}
		y++;
	}
}

void	ft_insrtgrass(t_program *prog, int i, int j)
{
	int	x;
	int	y;
	int	img_width;
	int	img_height;

	y = 0;
	i = 0;
	while (prog->map[i])
	{
		x = 0;
		j = 0;
		while (prog->map[i][j])
		{
			prog->img = mlx_xpm_file_to_image(prog->mlx, FLOOR,
					&img_width, &img_height);
			mlx_put_image_to_window(prog->mlx, prog->mlx_win, prog->img, x, y);
			x += 50;
			j++;
		}
		y += 50;
		i++;
	}
}

void	ft_insrt_img(t_program *prog, int x, int y)
{
	int	img_width;
	int	img_height;

	if (prog->map[y][x] == '1')
		prog->img = mlx_xpm_file_to_image(prog->mlx, WALL, &img_width,
				&img_height);
	else if (prog->map[y][x] == '0')
		prog->img = mlx_xpm_file_to_image(prog->mlx, FLOOR,
				&img_width, &img_height);
	else if (prog->map[y][x] == 'P')
		prog->img = mlx_xpm_file_to_image(prog->mlx, PLAYER_F,
				&img_width, &img_height);
	else if (prog->map[y][x] == 'C')
		prog->img = mlx_xpm_file_to_image(prog->mlx, COLLECT,
				&img_width, &img_height);
	else if (prog->map[y][x] == 'E')
		prog->img = mlx_xpm_file_to_image(prog->mlx, EXIT, &img_width,
				&img_height);
}

void	ft_get_map(t_program *prog)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	y = 0;
	ft_insrtgrass(prog, i, y);
	while (prog->map[i])
	{
		j = 0;
		x = 0;
		while (prog->map[i][j])
		{
			ft_insrt_img(prog, j, i);
			mlx_put_image_to_window(prog->mlx, prog->mlx_win, prog->img, x, y);
			j++;
			x += 50;
		}
		i++;
		y += 50;
	}
	ft_to_p(prog);
	ft_ct_c(prog);
}
