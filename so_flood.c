/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:44:47 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/20 21:43:32 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ct_c2(t_program2 *prog)
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

int	ft_fldfill(int x, int y, t_program2 *prog)
{
	if (prog->map[y][x] == '0' || prog->map[y][x] == 'P'
		|| prog->map[y][x] == 'C' || prog->map[y][x] == 'E')
	{
		if (prog->map[y][x] == 'C')
			prog->collect--;
		if (prog->map[y][x] == 'E')
			prog->exit++;
		prog->map[y][x] = 'M';
		if (ft_fldfill(x + 1, y, prog) || ft_fldfill(x - 1, y, prog)
			|| ft_fldfill(x, y + 1, prog) || ft_fldfill(x, y - 1, prog))
			return (1);
	}
	if (prog->collect == 0 && prog->exit >= 1)
		return (1);
	return (0);
}

void	ft_startpos(t_program2 *prog)
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
				prog->x_p = x;
				prog->y_p = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_init_fldfill(t_program2 *prog)
{
	int	x;
	int	y;

	ft_ct_c2(prog);
	ft_startpos(prog);
	x = prog->x_p;
	y = prog->y_p;
	if (!ft_fldfill(x, y, prog))
	{
		perror(E_PATH);
		exit(1);
	}
}
