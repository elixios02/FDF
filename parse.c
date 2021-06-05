/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:52:56 by paim              #+#    #+#             */
/*   Updated: 2016/11/22 21:07:06 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_charatoi(char c)
{
	return ((c >= 48 && c <= 57) || (c == 32 || c == 45) ? c : -1);
}

int			countgnl(int const fd, t_stock *t)
{
	int		i;
	int		ret;
	char	*line;

	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_strdel(&line);
		i++;
	}
	if (i == 0)
		return (error("map invalide"));
	if (ret == -1)
		return (error("map invalide"));
	if ((t->tab = (char **)ft_memalloc(sizeof(char *) * i + 1)) == NULL)
		return (-1);
	t->tab[i] = NULL;
	t->cgnl = i;
	return (0);
}

int			savetab(int const fd, t_stock *t)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	while ((ret = get_next_line(fd, &t->tab[i])) > 0)
	{
		j = 0;
		while (t->tab[i][j] != '\0')
		{
			if (ft_charatoi(t->tab[i][j]) == -1)
				return (-1);
			++j;
		}
		++i;
	}
	if (t->tab[0][0] == '\0')
		return (error("map invalide"));
	if (ret == -1)
		return (error("map invalide"));
	return (0);
}

int			mumuse(int argc, char **argv, t_stock *t)
{
	int		fd;
	int		i;
	int		(*f_fd[3])(int const fd, t_stock *);

	i = 0;
	f_fd[0] = countgnl;
	f_fd[1] = savetab;
	f_fd[2] = NULL;
	while (f_fd[i])
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		if (f_fd[i](fd, t) == -1)
			return (-1);
		close(fd);
		++i;
	}
	return (0);
}
