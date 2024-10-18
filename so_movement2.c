/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_movement2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:36:30 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/18 15:16:46 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_door(t_program *prog)
{
	prog->img = mlx_xpm_file_to_image(prog->mlx, EXIT, &prog->img_w,
			&prog->img_h);
	mlx_put_image_to_window(prog->mlx, prog->mlx_win, prog->img, prog->x_p,
		prog->y_p);
}

void	ft_gpath(t_program *prog)
{
	prog->img = mlx_xpm_file_to_image(prog->mlx, FLOOR, &prog->img_w,
			&prog->img_h);
	mlx_put_image_to_window(prog->mlx, prog->mlx_win, prog->img, prog->x_p,
		prog->y_p);
}

void	ft_to_e(t_program *prog)
{
	int	y;
	int	x;

	y = 0;
	while (prog->map[y])
	{
		x = 0;
		while (prog->map[y][x])
		{
			if (prog->map[y][x] == 'E')
			{
				prog->x_e = x * 50;
				prog->y_e = y * 50;
			}
			x++;
		}
		y++;
	}
}

void	opendoor(t_program *prog)
{
	ft_to_e(prog);
	prog->img = mlx_xpm_file_to_image(prog->mlx, O_EXIT, &prog->img_w,
			&prog->img_h);
	mlx_put_image_to_window(prog->mlx, prog->mlx_win, prog->img, prog->x_e,
		prog->y_e);
}
