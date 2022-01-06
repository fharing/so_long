/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putimage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:53:59 by fharing           #+#    #+#             */
/*   Updated: 2021/08/09 11:54:13 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	ft_put_images(char postition, t_vars *vars, t_counter *count)
{
	if (postition != '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->stone,
			count->y * 64, count->x * 64);
	if (postition == 'P' && vars->x == -1 && vars->y == -1)
		ft_putplayer(vars, count);
	else if (postition == 'C')
		ft_putcollectable(vars, count);
	else if (postition == 'E' && vars->exitx == -1 && vars->exity == -1)
		ft_putexit(vars, count);
	else if (postition == '1')
		ft_putwalls(vars, count);
	return (0);
}

int	ft_create_window(char *map, int width, int height)
{
	t_vars		vars;
	t_counter	count;

	ft_init_vars(&vars, width, height);
	ft_init_counter(&count);
	while (count.x < height)
	{
		count.y = 0;
		while (count.y < width)
		{
			ft_put_images(map[count.i], &vars, &count);
			count.y++;
			count.i++;
		}
		count.x++;
		count.i++;
	}
	vars.wallsmax = count.t;
	vars.collectmax = count.j;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, (1L << 17), close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
