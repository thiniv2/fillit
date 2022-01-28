/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:02:27 by thinguye          #+#    #+#             */
/*   Updated: 2019/12/11 16:48:15 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs.h"

void		print_map(t_map *map)
{
	int		y;

	y = 0;
	while (map->map[y])
	{
		ft_putendl(map->map[y]);
		y++;
	}
}

t_etri		*read_tetri(int fd, int mod)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	t_etri	*ptr;
	t_block	*list;

	ptr = NULL;
	list = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		mod = mod + ret;
		if (!(ft_valid_check(buf, 0, 0, 0)))
			print_error();
		ptr = create_list(ptr, ft_str_to_binary(buf, -1, 0, list));
	}
	if (mod % 21 != 20)
		print_error();
	return (ptr);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_etri	*ptr;
	t_map	*list;

	ptr = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit <source_file>");
		exit(0);
	}
	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1);
	if (!(ptr = read_tetri(fd, 0)))
		return (-1);
	set_coords(ptr);
	list = ft_generate_map(ptr, ft_smallest_square(ft_count_nodes(ptr) * 4));
	print_map(list);
	return (0);
}
