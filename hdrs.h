/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdrs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:34:39 by thinguye          #+#    #+#             */
/*   Updated: 2019/12/11 16:44:48 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HDRS_H
# define HDRS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUF_SIZE 21

typedef struct		s_cords
{
	int				x[4];
	int				y[4];
	struct s_cords	*next;
}					t_cords;

typedef struct		s_etri
{
	char			**tetri;
	char			c;
	int				int_arr_x[3];
	int				int_arr_y[3];
	struct s_etri	*next;
}					t_etri;

typedef struct		s_map
{
	int				size;
	char			**map;
}					t_map;

typedef struct		s_block
{
	unsigned int	block;
	unsigned int	binary;
}					t_block;

enum	e_type
{
	SRIGHT = 0x6C00,
	SLEFT = 0xC600,
	SURIGHT = 0x4C80,
	SULEFT = 0x8C40,
	LRIGHT = 0x88C0,
	LLEFT = 0x44C0,
	WLLEFT = 0xC440,
	WLRIGHT = 0xC880,
	SQUARE = 0xCC00,
	FLOOR = 0xF000,
	WALL = 0x8888,
	PYRAMID = 0x4e00,
	DPYRAMID = 0xe400,
	RPYRAMID = 0x8c80,
	LPYRAMID = 0x4c40,
	LLDRIGHT = 0xE200,
	LLURIGHT = 0x2E00,
	LLDLEFT = 0xE800,
	LLULEFT = 0x8E00,
};

int					ft_count_nodes(t_etri *ptr);
int					ft_smallest_square(int size);
int					ft_check_tetri(char *buf, int i, int x, int y);
int					ft_valid_check(char *buf, int i, int line, int row);
t_map				*ft_generate_map(t_etri *list, int size);
t_etri				*ft_tetri_to_list(char **arr);
void				set_coords(t_etri *list);
t_etri				*create_list(t_etri *ptr, char **arr);
void				print_map(t_map *map);
void				ft_free_list(t_etri **list);
void				ft_free_arr(char **arr);
char				**ft_str_to_binary(char *buf, int i, int x, t_block *list);
void				print_error(void);
#endif
