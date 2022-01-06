/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:53:15 by fharing           #+#    #+#             */
/*   Updated: 2021/08/09 13:59:02 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	ft_move_down(t_vars *vars)
{
	if (vars->straw > 0 && vars->y + 1 == vars->exity && vars->x == vars->exitx)
		return (0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->stone,
		vars->x * 64, vars->y * 64);
	vars->y++;
	vars->steps++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
		vars->x * 64, vars->y * 64);
	return (1);
}

int	ft_move_right(t_vars *vars)
{
	if (vars->straw > 0 && vars->x + 1 == vars->exitx && vars->y == vars->exity)
		return (0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->stone,
		vars->x * 64, vars->y * 64);
	vars->x++;
	vars->steps++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
		vars->x * 64, vars->y * 64);
	return (1);
}

int	ft_move_left(t_vars *vars)
{
	if (vars->straw > 0 && vars->x - 1 == vars->exitx && vars->y == vars->exity)
		return (0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->stone,
		vars->x * 64, vars->y * 64);
	vars->x--;
	vars->steps++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
		vars->x * 64, vars->y * 64);
	return (1);
}

int	ft_move_up(t_vars *vars)
{
	if (vars->straw > 0 && vars->y - 1 == vars->exity && vars->x == vars->exitx)
		return (0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->stone,
		vars->x * 64, vars->y * 64);
	vars->y--;
	vars->steps++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
		vars->x * 64, vars->y * 64);
	return (1);
}

int	key_hook(int keycode, t_vars *vars)
{
	if ((vars->straw == 0 && vars->x == vars->exitx
			&& vars->y == vars->exity) || keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 1 && ft_walls_yplus(vars) == 1)
		ft_move_down(vars);
	if (keycode == 2 && ft_walls_xplus(vars) == 1)
		ft_move_right(vars);
	if (keycode == 0 && ft_walls_xminus(vars) == 1)
		ft_move_left(vars);
	if (keycode == 13 && ft_walls_yminus(vars) == 1)
		ft_move_up(vars);
	if (ft_collect(vars) == 1 && vars->straw > 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->stone,
			vars->x * 64, vars->y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
			vars->x * 64, vars->y * 64);
		vars->straw--;
	}
	printf("NUMBER OF MOVES: %d\n", vars->steps);
	return (1);
}
