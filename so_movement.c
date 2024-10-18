/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 07:11:41 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/18 15:02:32 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collected(t_program *prog)
{
	prog->collect--;
	prog->map[prog->y_p / 50][prog->x_p / 50] = '0';
	prog->img = mlx_xpm_file_to_image(prog->mlx, FLOOR, &prog->img_w,
			&prog->img_h);
	mlx_put_image_to_window(prog->mlx, prog->mlx_win, prog->img, prog->x_p,
		prog->y_p);
	if (prog->collect == 0)
		opendoor(prog);
}

void	to_up(t_program *prog)
{
	ft_gpath(prog);
	if (prog->map[prog->y_p / 50][prog->x_p / 50] == 'E')
		ft_door(prog);
	if (prog->map[prog->y_p / 50 - 1][prog->x_p / 50] == 'E')
	{
		prog->y_p -= 50;
		if (prog->collect == 0)
			exit(0);
		ft_door(prog);
	}
	else if (prog->map[prog->y_p / 50 - 1][prog->x_p / 50] == '0'
		|| prog->map[prog->y_p / 50 - 1][prog->x_p / 50] == 'P')
	{
		prog->y_p -= 50;
	}
	else if (prog->map[prog->y_p / 50 - 1][prog->x_p / 50] == 'C')
	{
		prog->y_p -= 50;
		collected(prog);
	}
	prog->img = mlx_xpm_file_to_image(prog->mlx, PLAYER_B, &prog->img_w,
			&prog->img_h);
	mlx_put_image_to_window(prog->mlx, prog->mlx_win, prog->img, prog->x_p,
		prog->y_p);
	ft_printf("Moves done:%i\n", prog->move++);
}

void	to_down(t_program *prog)
{
	ft_gpath(prog);
	if (prog->map[prog->y_p / 50][prog->x_p / 50] == 'E')
		ft_door(prog);
	if (prog->map[prog->y_p / 50 + 1][prog->x_p / 50] == 'E')
	{
		prog->y_p += 50;
		if (prog->collect == 0)
			exit(0);
		ft_door(prog);
	}
	else if (prog->map[prog->y_p / 50 + 1][prog->x_p / 50] == '0'
		|| prog->map[prog->y_p / 50 + 1][prog->x_p / 50] == 'P')
	{
		prog->y_p += 50;
	}
	else if (prog->map[prog->y_p / 50 + 1][prog->x_p / 50] == 'C')
	{
		prog->y_p += 50;
		collected(prog);
	}
	prog->img = mlx_xpm_file_to_image(prog->mlx, PLAYER_F, &prog->img_w,
			&prog->img_h);
	mlx_put_image_to_window(prog->mlx, prog->mlx_win, prog->img, prog->x_p,
		prog->y_p);
	ft_printf("Moves done:%i\n", prog->move++);
}

void	to_left(t_program *prog)
{
	ft_gpath(prog);
	if (prog->map[prog->y_p / 50][prog->x_p / 50] == 'E')
		ft_door(prog);
	if (prog->map[prog->y_p / 50][prog->x_p / 50 - 1] == 'E')
	{
		prog->x_p -= 50;
		if (prog->collect == 0)
			exit(0);
		ft_door(prog);
	}
	else if (prog->map[prog->y_p / 50][prog->x_p / 50 - 1] == '0'
		|| prog->map[prog->y_p / 50][prog->x_p / 50 - 1] == 'P')
	{
		prog->x_p -= 50;
	}
	else if (prog->map[prog->y_p / 50][prog->x_p / 50 - 1] == 'C')
	{
		prog->x_p -= 50;
		collected(prog);
	}
	prog->img = mlx_xpm_file_to_image(prog->mlx, PLAYER_L, &prog->img_w,
			&prog->img_h);
	mlx_put_image_to_window(prog->mlx, prog->mlx_win, prog->img, prog->x_p,
		prog->y_p);
	ft_printf("Moves done:%i\n", prog->move++);
}

void	to_right(t_program *prog)
{
	ft_gpath(prog);
	if (prog->map[prog->y_p / 50][prog->x_p / 50] == 'E')
		ft_door(prog);
	if (prog->map[prog->y_p / 50][prog->x_p / 50 + 1] == 'E')
	{
		prog->x_p += 50;
		if (prog->collect == 0)
			exit(0);
		ft_door(prog);
	}
	else if (prog->map[prog->y_p / 50][prog->x_p / 50 + 1] == '0'
		|| prog->map[prog->y_p / 50][prog->x_p / 50 + 1] == 'P')
		prog->x_p += 50;
	else if (prog->map[prog->y_p / 50][prog->x_p / 50 + 1] == 'C')
	{
		prog->x_p += 50;
		collected(prog);
	}
	prog->img = mlx_xpm_file_to_image(prog->mlx, PLAYER_R, &prog->img_w,
			&prog->img_h);
	mlx_put_image_to_window(prog->mlx, prog->mlx_win, prog->img, prog->x_p,
		prog->y_p);
	ft_printf("Moves done:%i\n", prog->move++);
}
