/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:51:05 by thinguye          #+#    #+#             */
/*   Updated: 2019/12/11 14:37:02 by cleisti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs.h"

void	place_tetri(char **map, t_etri *list, int y, int x)
{
	int i;

	i = 0;
	map[y][x] = list->c;
	while (i < 3)
	{
		map[y + list->int_arr_y[i]][x + list->int_arr_x[i]] = list->c;
		i++;
	}
}

int		check_fit(t_map *map, t_etri *list, int y, int x)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 3 && y + list->int_arr_y[i] < map->size
		&& x + list->int_arr_x[i] < map->size && x + list->int_arr_x[i] >= 0)
	{
		if (map->map[y + list->int_arr_y[i]][x + list->int_arr_x[i]] == '.')
			count++;
		i++;
	}
	return (count == 3);
}

void	clear_piece(t_map *map, t_etri *list, int y, int x)
{
	int		i;

	i = 0;
	map->map[y][x] = '.';
	while (i < 3)
	{
		map->map[y + list->int_arr_y[i]][x + list->int_arr_x[i]] = '.';
		i++;
	}
}

int		tetri_to_map(t_map *map, t_etri *list)
{
	int		y;
	int		x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '.' && check_fit(map, list, y, x))
			{
				place_tetri(map->map, list, y, x);
				if (list->next == NULL || tetri_to_map(map, list->next))
					return (1);
				clear_piece(map, list, y, x);
			}
		}
	}
	return (0);
}

t_map	*ft_generate_map(t_etri *list, int size)
{
	int		y;
	t_map	*map;

	y = 0;
	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		map->map[y] = ft_memset(ft_strnew(size), '.', size);
		map->map[y][size] = '\0';
		y++;
	}
	map->map[size] = NULL;
	if (!tetri_to_map(map, list))
	{
		ft_free_arr(map->map);
		free(map);
		return (ft_generate_map(list, size + 1));
	}
	return (map);
}
