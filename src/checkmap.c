/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:52:34 by fharing           #+#    #+#             */
/*   Updated: 2021/08/09 11:52:56 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	ft_walls_yplus(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->wallsmax)
	{
		if (vars->y + 1 == vars->walls[i][0] && vars->x == vars->walls[i][1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_walls_xplus(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->wallsmax)
	{
		if (vars->y == vars->walls[i][0] && vars->x + 1 == vars->walls[i][1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_walls_xminus(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->wallsmax)
	{
		if (vars->y == vars->walls[i][0] && vars->x - 1 == vars->walls[i][1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_walls_yminus(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->wallsmax)
	{
		if (vars->y - 1 == vars->walls[i][0] && vars->x == vars->walls[i][1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_collect(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->collectmax)
	{
		if (vars->y == vars->collects[i][0]
			&& vars->x == vars->collects[i][1])
		{
			vars->collects[i][0] = -1;
			vars->collects[i][1] = -1;
			return (1);
		}
		i++;
	}
	return (0);
}
