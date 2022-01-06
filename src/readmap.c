/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:50:07 by fharing           #+#    #+#             */
/*   Updated: 2021/08/09 11:50:42 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	ft_lastline(char *map)
{
	int	i;

	i = ft_strlen(map) - 1;
	while (i > 0 && map[i] != '\n')
	{
		if (map[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

int	ft_check_walls(char *map)
{
	int	i;
	int	firstline;

	firstline = 1;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			firstline = 0;
			if (map[i + 1] != '\0' && map[i + 1] != '1')
				return (0);
			if (map[i - 1] != '1')
				return (0);
		}
		if (firstline == 1 && map[i] != '1')
			return (0);
		i++;
	}
	if (ft_lastline(map) == 0)
		return (0);
	return (1);
}

int	ft_line_length(char *map, t_map *valid_map)
{
	int	i;
	int	line;
	int	tmp;

	i = 0;
	line = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			line = i;
			if (valid_map->x != 0 && line - tmp - 1 != valid_map->x)
				return (0);
			tmp = line;
			valid_map->y++;
			if (valid_map->x == 0)
				valid_map->x = line;
		}
		i++;
	}
	if (valid_map->x != 0 && i - tmp - 1 != valid_map->x)
		return (0);
	return (1);
}

int	ft_check_letter(char *map, t_map *valid_map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
			return (0);
		if (map[i] == 'C')
			valid_map->c++;
		if (map[i] == 'E')
			valid_map->e++;
		if (map[i] == 'P')
			valid_map->p++;
		i++;
	}
	return (1);
}

int	ft_checkmap(char *map, int *width, int *height)
{
	int		i;
	t_map	valid_map;

	i = 0;
	ft_init_map(&valid_map);
	if (ft_check_letter(map, &valid_map) == 0 || ft_check_walls(map) == 0
		|| ft_line_length(map, &valid_map) == 0
		|| ft_validate_map(&valid_map) == 0)
		return (0);
	*width = valid_map.x;
	*height = valid_map.y + 1;
	return (1);
}
