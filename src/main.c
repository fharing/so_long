/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:22:28 by fharing           #+#    #+#             */
/*   Updated: 2021/08/09 16:58:59 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	main(int argc, char *argv[])
{
	int		width;
	int		height;
	char	*map;

	if (argc != 2)
	{
		printf("Error\nMISSING MAP!\n");
		return (0);
	}
	map = ft_readmap(argv[1]);
	if (map == NULL)
	{
		printf("Error\nCAN'T FIND A MAP: %s", argv[1]);
		return (0);
	}
	if (ft_checkmap(map, &width, &height) == 0)
	{
		printf("Error\nNOT A GOOD MAP!");
		free (map);
		return (0);
	}
	ft_create_window(map, width, height);
	free (map);
	return (0);
}
