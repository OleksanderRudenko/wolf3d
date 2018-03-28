/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:53:18 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/12 16:47:51 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

SDL_Surface	*load_image(char *filepath)
{
	SDL_Surface	*surf;

	surf = IMG_Load(filepath);
	if (surf == NULL)
	{
		ft_putendl(IMG_GetError());
		exit(0);
	}
	return (surf);
}
