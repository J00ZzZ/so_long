/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:52:37 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/24 08:35:17 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rectangle(t_program2 *prog)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = prog->width;
	while (y < prog->height)
	{
		x = 0;
		while (prog->map[y][x])
		{
			x++;
		}
		if (x != prog->width)
		{
			perror(E_MAP);
			exit(1);
		}
		y++;
	}
}

void	ft_err_elm(t_map_prog *map)
{
	if (map->c == 0)
	{
		perror(E_C_ELM);
		exit(1);
	}
	else if (map->p == 0 || map->p > 1)
	{
		perror(E_P_ELM);
		exit(1);
	}
	else if (map->e == 0 || map->e > 1)
	{
		perror(E_E_ELM);
		exit(1);
	}
}

void	ft_ukn(t_program2 *prog)
{
	free(prog->map);
	perror(E_UKN);
	exit(1);
}

void	ft_content(t_program2 *prog)
{
	t_map_prog	map;

	map.c = 0;
	map.e = 0;
	map.p = 0;
	map.y = -1;
	while (prog->map[++map.y])
	{
		map.x = 0;
		while (prog->map[map.y][map.x])
		{
			if (prog->map[map.y][map.x] == 'P')
				map.p++;
			else if (prog->map[map.y][map.x] == 'C')
				map.c++;
			else if (prog->map[map.y][map.x] == 'E')
				map.e++;
			else if (prog->map[map.y][map.x] != '1'
				&& prog->map[map.y][map.x] != '0')
				ft_ukn(prog);
			map.x++;
		}
	}
	ft_err_elm(&map);
}

void	ft_check_map(t_program2 *prog)
{
	int	y;

	y = 0;
	ft_content(prog);
	ft_rectangle(prog);
	ft_wall(prog);
	ft_init_fldfill(prog);
	while (prog->map[y])
	{
		free(prog->map[y]);
		y++;
	}
}
