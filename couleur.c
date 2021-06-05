/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 11:36:20 by paim              #+#    #+#             */
/*   Updated: 2016/11/18 15:46:04 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color_alt(t_stock *t)
{
	int	b;
	int	g;
	int	r;

	b = 0;
	g = 0;
	r = 0;
	if (t->color == 0)
		t->cc = 0xFFFFFF;
	else if (t->color < 0)
		t->cc = 0x289587;
	else if (t->color > 0)
		t->cc = 0x00FAD9;
	return (0);
}
