/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:57:36 by fharing           #+#    #+#             */
/*   Updated: 2021/08/09 13:59:46 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	ft_init_vars(t_vars *vars, int width, int height)
{
	int	img_width;
	int	img_height;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, width * 64,
			height * 64, "The game of the great felix!");
	vars->stone = mlx_xpm_file_to_image(vars->mlx,
			"./img/stone.xpm", &img_width, &img_height);
	vars->player = mlx_xpm_file_to_image(vars->mlx,
			"./img/player.xpm", &img_width, &img_height);
	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"./img/wall.xpm", &img_width, &img_height);
	vars->collect = mlx_xpm_file_to_image(vars->mlx,
			"./img/collect.xpm", &img_width, &img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx,
			"./img/exit.xpm", &img_width, &img_height);
	vars->straw = 0;
	vars->steps = 0;
	vars->height = height;
	vars->width = width;
	vars->x = -1;
	vars->y = -1;
	vars->exitx = -1;
	vars->exity = -1;
}

void	ft_init_counter(t_counter *count)
{
	count->x = 0;
	count->j = 0;
	count->i = 0;
	count->t = 0;
}

int	close_window(void)
{
	exit(0);
}
