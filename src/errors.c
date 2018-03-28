/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:57:49 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/12 14:00:48 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

void	fck_up(void)
{
	ft_putendl("usage: ./wolf3d [map name]");
	exit(0);
}

void	mal_er(void)
{
	ft_putendl("Malloc fails");
	exit(0);
}

void	line_er(void)
{
	ft_putendl("Error: invalid map");
	exit(0);
}

void	bad_position(void)
{
	ft_putendl("Error: invalid player position");
	exit(0);
}
