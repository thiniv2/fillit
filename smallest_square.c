/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 10:22:47 by thinguye          #+#    #+#             */
/*   Updated: 2019/12/11 16:46:25 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs.h"

void	print_error(void)
{
	ft_putendl("error");
	exit(0);
}

int		ft_count_nodes(t_etri *ptr)
{
	int		i;

	i = 0;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	if (i > 26)
	{
		print_error();
	}
	return (i);
}

int		ft_smallest_square(int size)
{
	int		count;

	count = 2;
	while (count * count < size)
		count++;
	return (count);
}
