/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntordjma <ntordjma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:13:14 by ntordjma          #+#    #+#             */
/*   Updated: 2025/02/24 16:42:00 by ntordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

void	gen_map(char **map)
{
	int x = 0;
	int y = 0;

	while (map[y])
	{
		while (map[y][x])
		{
			switch (map[y][x])
			{
				case "O"
				case "X"
				case "1"
				case "O" // etc...
			}
			x++;
		}
		x = 0;
		y++;
	}
}