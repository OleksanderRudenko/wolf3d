#include "woof.h"

int	**init_floor(t_sdl_manange *s)
{
	int i;
	int j;
	int	**arr;
	char **paiste;
	t_flist *tmp;

	i = -1;
	tmp = s->begin;
	if (!(arr = (int **)malloc(sizeof(int *) * tmp->vert)))
		mal_er();
	while (++i < tmp->vert && tmp->next)
	{
		j = -1;
		if (!(arr[i] = (int *)malloc(sizeof(int) * tmp->hor)))
			mal_er();
		paiste = ft_strsplit(tmp->line, ' ');
		while (++j < tmp->hor)
		{
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
	if (get_next_line(fd, &line) < 0)
		fck_up();
	tmp->param = ft_strdup(line);
	ft_strdel(&line);
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
	horiz = ft_num_words(head->line, ' ');
	vertic = list_size(head);
	while (tmp->next)
	{
		tmp->hor = ft_num_words(tmp->line, ' ');
		if (tmp->hor != horiz)
		{
			ft_putendl("Error: wrong num of lines");
			exit(0);
		}
		tmp->vert = vertic;
		tmp = tmp->next;
	}
}

int		list_size(t_flist *head)
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