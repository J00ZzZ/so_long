/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:31:02 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/17 11:38:56 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_file_error(int argc, char **argv)
{
	if (argc != 2 || ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		perror(E_FILE);
		exit(1);
	}
}

void	init_vars2(t_program2 *prog)
{
	prog->move = 0;
	prog->collect = 0;
	prog->width = ft_strlen(prog->map[0]);
	prog->height = ft_height(prog->map);
	prog->x_p = 0;
	prog->y_p = 0;
}

void	init_vars(t_program *prog)
{
	prog->collect = 0;
	prog->move = 0;
	prog->width = ft_strlen(prog->map[0]);
	prog->height = ft_height(prog->map);
	prog->x_p = 0;
	prog->y_p = 0;
	prog->x_e = 0;
	prog->y_e = 0;
}
