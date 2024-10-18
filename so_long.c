/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:09:44 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/20 21:41:25 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_program *prog)
{
	int	x;

	if (keycode == 2 || keycode == 124)
		to_right(prog);
	else if (keycode == 0 || keycode == 123)
		to_left(prog);
	else if (keycode == 13 || keycode == 126)
		to_up(prog);
	else if (keycode == 1 || keycode == 125)
		to_down(prog);
	else if (keycode == 53)
	{
		x = 0;
		while (prog->map[x])
		{
			free(prog->map[x]);
			x++;
		}
		free(prog->map);
		mlx_destroy_window(prog->mlx, prog->mlx_win);
		exit(1);
	}
	return (0);
}

int	ft_exit(t_program *prog)
{
	int	x;

	x = 0;
	while (prog->map[x])
	{
		free(prog->map[x]);
		x++;
	}
	free(prog->map);
	mlx_destroy_window(prog->mlx, prog->mlx_win);
	exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	prog;
	t_program2	prog2;

	ft_check_file_error(argc, argv);
	prog.map = ft_map(argv[1]);
	prog2.map = ft_map(argv[1]);
	if (!prog.map || !prog2.map)
		return (0);
	init_vars2(&prog2);
	init_vars(&prog);
	ft_check_map(&prog2);
	prog.mlx = mlx_init();
	if (prog.width >= 40 || prog.height >= 22)
	{
		perror(E_BIG);
		exit(1);
	}
	prog.mlx_win = mlx_new_window(prog.mlx, prog.width * 50, prog.height * 50,
			"SO_LONG");
	ft_get_map(&prog);
	mlx_hook(prog.mlx_win, 2, (1L << 0), key_hook, &prog);
	mlx_hook(prog.mlx_win, 17, (1L << 0), ft_exit, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
