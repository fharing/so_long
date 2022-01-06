/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:50:07 by fharing           #+#    #+#             */
/*   Updated: 2021/08/09 13:42:18 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

char	*ft_read_loop(int bytesred, char buff[2], int fd)
{
	char	*tmp;
	char	*str;

	str = NULL;
	while (bytesred > 0)
	{
		buff[bytesred] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str, buff);
			free (str);
			str = tmp;
		}
		bytesred = read(fd, buff, 1);
	}
	return (str);
}

char	*ft_readmap(char *map)
{
	char	*str;
	int		fd;
	char	buff[2];
	int		bytesred;

	str = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	bytesred = read(fd, buff, 1);
	if (bytesred > 0)
		str = ft_read_loop(bytesred, buff, fd);
	if (close(fd) == -1)
		return (0);
	return (str);
}

void	ft_init_map(t_map *valid_map)
{
	valid_map->e = 0;
	valid_map->p = 0;
	valid_map->c = 0;
	valid_map->x = 0;
	valid_map->y = 0;
}

int	ft_validate_map(t_map *valid_map)
{
	if (valid_map->e >= 1 && valid_map->p >= 1 && valid_map->c >= 1
		&& valid_map->x >= 1 && valid_map->y >= 1)
		return (1);
	return (0);
}
