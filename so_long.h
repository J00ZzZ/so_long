/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:41:57 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/18 18:49:40 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mainlibft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

/* Errors */

# define E_FILE "ERROR: Format is ./so_long <file.ber>\n"
# define E_MAP "ERROR: The map must be rectangular\n"
# define E_UKN "ERROR: Unknown element\n"
# define E_C_ELM "ERROR: Please insert at least 1 Collectables\n"
# define E_P_ELM "ERROR: Please insert 1 Player\n"
# define E_E_ELM "ERROR: Please insert 1 Exit\n"
# define E_WALL "ERROR: Map must be surround by wall\n"
# define E_PATH "ERROR: Map did not reach exit condition\n"
# define E_BIG "ERROR: Map is too big\n"

/* Sprites */
# define WALL "img/wall.xpm"
# define FLOOR "img/floor.xpm"
# define PLAYER_F "img/front.xpm"
# define PLAYER_B "img/back.xpm"
# define PLAYER_L "img/left.xpm"
# define PLAYER_R "img/right.xpm"
# define COLLECT "img/collect.xpm"
# define O_EXIT "img/o_exit.xpm"
# define EXIT "img/exit.xpm"

/* Struct */

typedef struct s_map_prog
{
	int		c;
	int		p;
	int		e;
	int		x;
	int		y;
}			t_map_prog;

typedef struct s_program2
{
	char	**map;
	int		collect;
	int		exit;
	int		count;
	int		move;
	int		width;
	int		height;
	int		x_p;
	int		y_p;
}			t_program2;

typedef struct s_program
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	**map;
	int		count;
	int		collect;
	int		move;
	int		width;
	int		height;
	int		x_p;
	int		y_p;
	int		x_e;
	int		y_e;
	int		img_w;
	int		img_h;
}			t_program;

/* Functions */
void		init_vars(t_program *prog);
void		ft_check_file_error(int argc, char **argv);
char		**ft_map(char *str);
int			ft_height(char **str);
void		ft_check_map(t_program2 *prog);
void		ft_content(t_program2 *prog);
void		ft_ukn(t_program2 *prog);
void		ft_err_elm(t_map_prog *map);
void		ft_map_error(void);
void		ft_wall(t_program2 *prog);
void		ft_last(t_program2 *prog);
void		ft_first(t_program2 *prog);
void		ft_side(t_program2 *prog);
void		ft_init_fldfill(t_program2 *prog);
void		ft_startpos(t_program2 *flood);
void		ft_get_map(t_program *prog);
void		init_vars2(t_program2 *prog);
void		ft_check_file_error(int argc, char **argv);
int			ft_fldfill(int x, int y, t_program2 *prog);

void		to_up(t_program *prog);
void		to_down(t_program *prog);
void		to_left(t_program *prog);
void		to_right(t_program *prog);
void		ft_to_p(t_program *prog);
void		ft_ct_c(t_program *prog);
void		collected(t_program *prog);
void		opendoor(t_program *prog);
void		ft_to_e(t_program *prog);
void		ft_ct_c2(t_program2 *prog);
void		ft_gpath(t_program *prog);
void		ft_door(t_program *prog);

#endif