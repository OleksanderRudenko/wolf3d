/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:23:47 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/26 11:12:41 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

int		ft_isalpha_str(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

void	check_valid_map(t_sdl_manange *s)
{
	int		i;
	int		size;

	i = 0;
	size = list_size(s->begin);
	while (i < size - 1)
		if (s->floor[i++][0] == 0 && !(ft_isdigit(s->floor[i][0])))
			line_er();
	i = 0;
	while (i < s->begin->hor)
		if (s->floor[0][i++] == 0 && !(ft_isdigit(s->floor[0][i])))
			line_er();
	i = 0;
	while (i < size - 1)
	{
		if (s->floor[i++][s->begin->hor - 1] == 0 &&
			!(ft_isdigit(s->floor[i][s->begin->hor - 1])))
			line_er();
	}
	i = 0;
	while (i < s->begin->hor)
		if (s->floor[size - 1][i++] == 0 &&
			!(ft_isdigit(s->floor[size - 1][i])))
			line_er();
}

void	check_valid_map3(t_sdl_manange *s)
{
	int		i;
	int		size;

	i = 0;
	size = list_size(s->begin);
	while (i < size - 1)
		if (s->floor[i++][0] == 7 && !(ft_isdigit(s->floor[i][0])))
			line_er();
	i = 0;
	while (i < s->begin->hor)
		if (s->floor[0][i++] == 7 && !(ft_isdigit(s->floor[0][i])))
			line_er();
	i = 0;
	while (i < size - 1)
	{
		if (s->floor[i++][s->begin->hor - 1] == 7 &&
			!(ft_isdigit(s->floor[i][s->begin->hor - 1])))
			line_er();
	}
	i = 0;
	while (i < s->begin->hor)
		if (s->floor[size - 1][i++] == 7 &&
			!(ft_isdigit(s->floor[size - 1][i])))
			line_er();
}

void	check_valid_map2(t_sdl_manange *s)
{
	int		i;
	int		j;

	i = 0;
	while (i < s->begin->vert)
	{
		j = 0;
		while (j < s->begin->hor)
		{
			if (s->floor[i][j] < 0 || s->floor[i][j] > 7)
				line_er();
			j++;
		}
		i++;
	}
}
