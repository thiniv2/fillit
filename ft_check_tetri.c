/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:36:14 by thinguye          #+#    #+#             */
/*   Updated: 2019/12/11 16:45:15 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs.h"

void	ft_free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int		ft_check_con(char **arr, t_cords *coord, int i, int count)
{
	if ((coord->y[i] > 0) && (arr[coord->y[i] - 1][coord->x[i]] == '#'))
		count++;
	if ((coord->y[i] < 3) && (arr[coord->y[i] + 1][coord->x[i]] == '#'))
		count++;
	if ((coord->x[i] < 3) && (arr[coord->y[i]][coord->x[i] + 1] == '#'))
		count++;
	if ((coord->x[i] > 0) && (arr[coord->y[i]][coord->x[i] - 1] == '#'))
		count++;
	if (i == 3 && (count == 6 || count == 8))
		return (1);
	else if (i != 3)
		return (ft_check_con(arr, coord, i + 1, count));
	return (0);
}

int		ft_check_tetri(char *buf, int i, int x, int y)
{
	t_cords *coord;
	char	**arr;

	if (!(arr = ft_strsplit(buf, '\n')))
		return (0);
	if (!(coord = malloc(sizeof(t_cords))))
		return (0);
	while (++y < 4)
	{
		x = -1;
		while (x++ < 4)
		{
			if (arr[y][x] == '#')
			{
				coord->x[i] = x;
				coord->y[i++] = y;
			}
		}
	}
	if (i != 4 || ft_check_con(arr, coord, 0, 0) == 0)
		print_error();
	ft_free_arr(arr);
	free(coord);
	return (1);
}

int		ft_valid_check(char *buf, int i, int line, int row)
{
	while (buf[i] != '\0')
	{
		if ((buf[i] == '\n' && buf[i - 1] != '\n') || (line > 4))
		{
			if (line != 4)
				return (0);
			line = 0;
			i++;
			row++;
		}
		if (buf[i - 1] == '\n' && (buf[i] == '\n' || buf[i] == '\0'))
		{
			if (row != 4)
				return (0);
			row = 0;
			i++;
		}
		if (buf[i] != '.' && buf[i] != '#' &&
			buf[i] != '\n' && buf[i + 1] != '\0')
			return (0);
		i++;
		line++;
	}
	return (ft_check_tetri(buf, 0, 0, -1));
}
