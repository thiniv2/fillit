/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:46:22 by thinguye          #+#    #+#             */
/*   Updated: 2019/12/11 13:24:43 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs.h"

char		**set_null(char **arr, int *y, int *x, int *i)
{
	arr[*y][*x] = '\0';
	*y = *y + 1;
	*x = -1;
	*i = *i + 1;
	return (arr);
}

char		**ft_binary_to_arr(t_block *list, int i, int y, int x)
{
	int		ret;
	char	**arr;

	if (!(arr = (char**)malloc(sizeof(char*) * 4)))
		return (NULL);
	while (y < 4)
	{
		if (x == 0)
			if (!(arr[y] = (char*)malloc(sizeof(char) * 5)))
				return (NULL);
		ret = list->block >> i;
		if (ret & 1)
			arr[y][x] = '#';
		else
			arr[y][x] = '.';
		if (x == 4)
			arr = set_null(arr, &y, &x, &i);
		x++;
		i--;
	}
	free(list);
	return (arr);
}

char		**ft_move_to_optimal(t_block *list, int i)
{
	while (i++ <= 21)
	{
		if (list->block == SRIGHT || list->block == SLEFT)
			break ;
		if (list->block == SURIGHT || list->block == SULEFT)
			break ;
		if (list->block == LRIGHT || list->block == LLEFT)
			break ;
		if (list->block == WLLEFT || list->block == WLRIGHT)
			break ;
		if (list->block == SQUARE)
			break ;
		if (list->block == FLOOR || list->block == WALL)
			break ;
		if (list->block == PYRAMID || list->block == DPYRAMID)
			break ;
		if (list->block == RPYRAMID || list->block == LPYRAMID)
			break ;
		if (list->block == LLDRIGHT || list->block == LLURIGHT)
			break ;
		if (list->block == LLDLEFT || list->block == LLULEFT)
			break ;
		list->block <<= 1;
	}
	return (ft_binary_to_arr(list, 15, 0, 0));
}

char		**ft_str_to_binary(char *buf, int i, int x, t_block *list)
{
	char	**arr;

	arr = ft_strsplit(buf, '\n');
	if (!(list = malloc(sizeof(t_block))))
		return (NULL);
	while (++i <= 3)
	{
		x = -1;
		while (arr[i][++x])
		{
			if (arr[i][x] == '#')
			{
				list->block += 1;
				list->block <<= 1;
			}
			if (arr[i][x] == '.')
			{
				list->block += 0;
				list->block <<= 1;
			}
		}
	}
	ft_free_arr(arr);
	list->block >>= 1;
	return (ft_move_to_optimal(list, 0));
}
