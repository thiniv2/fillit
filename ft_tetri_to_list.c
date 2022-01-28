/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleisti <cleisti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:55:27 by cleisti           #+#    #+#             */
/*   Updated: 2019/12/12 13:11:18 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs.h"

void		free_list_content(char **tetri)
{
	int i;

	i = 0;
	while (tetri[i])
	{
		free(tetri[i]);
		tetri[i] = NULL;
		i++;
	}
}

void		ft_free_list(t_etri **list)
{
	t_etri	*ptr;

	while (*list)
	{
		ptr = (*list)->next;
		free_list_content((*list)->tetri);
		free(*list);
		*list = ptr;
	}
}

void		ft_addnode(t_etri **alst, t_etri *new)
{
	t_etri *ptr;

	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

t_etri		*ft_tetri_to_list(char **arr)
{
	t_etri		*node;
	int			i;
	static char	alpha = 'A';

	i = 0;
	if (!(node = malloc(sizeof(t_etri))))
		return (NULL);
	if (!(node->tetri = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	while (i < 4)
	{
		if (!(node->tetri[i] = (char*)malloc(sizeof(char) * 5)))
			return (NULL);
		ft_memcpy(node->tetri[i], arr[i], ft_strlen(arr[i]));
		free(arr[i]);
		i++;
	}
	free(arr);
	node->c = alpha;
	alpha++;
	node->tetri[i] = NULL;
	node->next = NULL;
	return (node);
}

t_etri		*create_list(t_etri *ptr, char **arr)
{
	t_etri	*node;

	if (ptr == NULL)
		ptr = ft_tetri_to_list(arr);
	else
	{
		node = ft_tetri_to_list(arr);
		ft_addnode(&ptr, node);
	}
	return (ptr);
}
