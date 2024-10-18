/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:43:02 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/24 08:35:07 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_error(void)
{
	perror(E_MAP);
	exit(1);
}

int	ft_height(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_join(char *localmap, char *tmp)
{
	char	*tmp2;

	tmp2 = localmap;
	localmap = ft_strjoin(localmap, tmp);
	free(tmp2);
	free(tmp);
	return (localmap);
}

char	**ft_map(char *str)
{
	int		fd;
	char	*tmp;
	char	*localmap;
	char	**split;

	tmp = "";
	localmap = ft_strdup("");
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_map_error();
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL || tmp[0] == '\n')
			break ;
		localmap = ft_join(localmap, tmp);
	}
	free(tmp);
	close(fd);
	if (localmap[0] == '\0')
		ft_map_error();
	split = ft_split(localmap, '\n');
	free(localmap);
	return (split);
}
