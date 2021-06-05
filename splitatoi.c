/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitatoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 12:32:34 by paim              #+#    #+#             */
/*   Updated: 2016/06/17 16:40:39 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			atoicoord(t_stock *t, char **argv)
{
	int		k;
	int		l;
	char	**str;
	int		m;

	m = 0;
	l = 0;
	k = 0;
	while (t->tab[l] != NULL)
	{
		if ((str = ft_strsplit(t->tab[l], ' ')) == NULL)
			return (-1);
		k = 0;
		while (str[m] != NULL)
		{
			t->coord[t->p][k] = ft_atoi(str[m]);
			k++;
			m++;
		}
		t->p++;
		m = 0;
		l++;
	}
	return (0);
}

int			checkline(t_stock *t)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	if ((str = ft_strsplit(t->tab[0], ' ')) == NULL)
		return (-1);
	while (str[k] != NULL)
		k++;
	while (t->tab[i] != NULL)
	{
		if ((str = ft_strsplit(t->tab[i], ' ')) == NULL)
			return (-1);
		while (str[j] != NULL)
			j++;
		i++;
		if (k != j)
			return (-1);
	}
	return (k);
}

int			splitatoi(char **argv, t_stock *t)
{
	char	**str;
	int		j;
	int		i;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if ((j = checkline(t)) == -1)
		return (-1);
	while (t->tab[i] != NULL)
		i++;
	t->ordo = i;
	t->abs = j;
	if ((t->coord = (int**)malloc(sizeof(int*) * (i))) == 0)
		return (-1);
	while (k != i)
	{
		if ((t->coord[k] = (int*)malloc(sizeof(int) * (j))) == 0)
			return (-1);
		k++;
	}
	if (atoicoord(t, argv) != 0)
		return (-1);
	return (0);
}
