/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:55:27 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/20 17:49:09 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

int			**init_floor(t_sdl_manange *s)
{
	int		i;
	int		j;
	int		**arr;
	char	**paiste;
	t_flist	*tmp;

	i = -1;
	tmp = s->begin;
	!(arr = (int **)malloc(sizeof(int *) * tmp->vert)) ? mal_er() : 0;
	while (++i < tmp->vert && tmp->next)
	{
		j = -1;
		if (!(arr[i] = (int *)malloc(sizeof(int) * tmp->hor)))
			mal_er();
		paiste = ft_strsplit(tmp->line, ' ');
		while (++j < tmp->hor)
		{
			ft_isalpha_str(paiste[j]) ? line_er() : 0;
			arr[i][j] = ft_atoi(paiste[j]);
		}
		free_double(paiste);
		tmp = tmp->next;
	}
	return (arr);
}

t_flist		*read_file(char *str)
{
	int			fd;
	char		*line;
	t_flist		*xd;
	t_flist		*tmp;

	if ((fd = open(str, O_RDONLY)) == -1)
		fck_up();
	xd = (t_flist *)malloc(sizeof(t_flist));
	tmp = xd;
	if (get_next_line(fd, &line) <= 0)
		fck_up();
	tmp->param = ft_strdup(line);
	ft_strdel(&line);
	ft_strcmp(tmp->param, "") == 0 ? line_er() : 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp->line = ft_strdup(line);
		tmp->next = (t_flist *)malloc(sizeof(t_flist));
		tmp = tmp->next;
		ft_strdel(&line);
	}
	tmp->next = NULL;
	close(fd);
	return (xd);
}

void		count_symbols(t_flist *head)
{
	t_flist		*tmp;
	int			horiz;
	int			vertic;

	tmp = head;
	if (head->next == NULL || head == NULL)
		line_er();
	horiz = ft_num_words(head->line, ' ');
	vertic = list_size(head);
	if (vertic < 3 || vertic > 1024)
		line_er();
	while (tmp->next)
	{
		tmp->hor = ft_num_words(tmp->line, ' ');
		if (tmp->hor != horiz)
			line_er();
		tmp->vert = vertic;
		tmp = tmp->next;
	}
}

int			list_size(t_flist *head)
{
	int		i;
	t_flist	*tmp;

	tmp = head;
	i = 0;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
