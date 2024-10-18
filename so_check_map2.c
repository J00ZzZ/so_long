/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:56:08 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/17 09:56:34 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_first(t_program2 *prog)
{
	int	y;
	int	x;

	y = 0;
	while (prog->map[y])
	{
		x = 0;
		while (prog->map[y][x])
		{
			if (prog->map[0][x] != '1')
			{
				perror(E_WALL);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	ft_side(t_program2 *prog)
{
	int	x;
	int	y;
	int	last;

	last = prog->width;
	y = 0;
	while (prog->map[y])
	{
		x = 0;
		while (prog->map[y][x])
		{
			if (prog->map[y][0] != '1' || prog->map[y][last - 1] != '1')
			{
				perror(E_WALL);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	ft_last(t_program2 *prog)
{
	int	x;
	int	y;

	y = 0;
	while (prog->map[y])
		y++;
	x = 0;
	while (prog->map[y - 1][x])
	{
		if (prog->map[y - 1][x] != '1')
		{
			perror(E_WALL);
			exit(1);
		}
		x++;
	}
}

void	ft_wall(t_program2 *prog)
{
	ft_first(prog);
	ft_side(prog);
	ft_last(prog);
}
