/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:55:28 by thinguye          #+#    #+#             */
/*   Updated: 2019/12/11 12:51:51 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs.h"

void	coords_to_list(t_etri *list, int *arr)
{
	list->int_arr_x[arr[2]] = arr[1] - arr[5];
	list->int_arr_y[arr[3]] = arr[0] - arr[6];
	arr[2] += 1;
	arr[3] += 1;
}

void	set_coords(t_etri *list)
{
	int		*arr;

	arr = (int*)malloc(sizeof(int) * 7);
	arr[2] = 0;
	arr[3] = 0;
	arr[4] = 0;
	arr[0] = -1;
	while (list->tetri[++arr[0]] != NULL)
	{
		arr[1] = -1;
		while (list->tetri[arr[0]][++arr[1]])
		{
			if (list->tetri[arr[0]][arr[1]] == '#' && arr[4] == 0)
			{
				arr[5] = arr[1];
				arr[6] = arr[0];
				arr[4] = 1;
			}
			else if (list->tetri[arr[0]][arr[1]] == '#' && arr[4] == 1)
				coords_to_list(list, arr);
		}
	}
	free(arr);
	if (list->next)
		set_coords(list->next);
}
