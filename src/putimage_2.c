/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimage_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:54:53 by fharing           #+#    #+#             */
/*   Updated: 2021/08/09 11:55:06 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	ft_putplayer(t_vars *vars, t_counter *count)
{
	vars->x = count->y;
	vars->y = count->x;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
		count->y * 64, count->x * 64);
	return ;
}

void	ft_putcollectable(t_vars *vars, t_counter *count)
{
	vars->straw++;
	vars->collects[count->j][0] = count->x;
	vars->collects[count->j][1] = count->y;
	count->j++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->collect,
		count->y * 64, count->x * 64);
	return ;
}

void	ft_putexit(t_vars *vars, t_counter *count)
{
	vars->exitx = count->y;
	vars->exity = count->x;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit,
		count->y * 64, count->x * 64);
	return ;
}

void	ft_putwalls(t_vars *vars, t_counter *count)
{
	vars->walls[count->t][0] = count->x;
	vars->walls[count->t][1] = count->y;
	count->t++;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->wall,
		count->y * 64, count->x * 64);
	return ;
}
