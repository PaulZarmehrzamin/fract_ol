/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 16:58:48 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/16 16:47:47 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>

int		line_len(int n)
{
	int		len;

	len = WIN_SIZE / 3;
	while (n >= 0)
	{
		len = len * 11 / 16;
		n--;
	}
	return (len);
}

void	line(t_env *env, t_point p1, float angle)
{
	int		len;
	int		i;
	float	x;
	float	y;
	int		color;

	color = get_color(env->nn, env->color, env->rainbow);
	len = line_len(env->nn);
	i = 0;
	while (i <= len)
	{
		x = p1.x + i * cos(angle);
		y = p1.y - i * sin(angle);
		img_pixel_put(env, x, y, color);
		i++;
	}
}

void	draw_tree(t_env *env, t_point p1, t_point p2, float angle)
{
	t_point	p3;
	int		len;

	if (env->nn <= env->n)
	{
		line(env, p1, angle);
		(env->nn)++;
		if ((len = line_len(env->nn)))
		{
			p3.x = p2.x + len * cos(angle + M_PI * 5 / 12);
			p3.y = p2.y - len * sin(angle + M_PI * 5 / 12);
			draw_tree(env, p2, p3, angle + M_PI * 5 / 12);
			p3.x = p2.x + len * cos(angle - M_PI / 6);
			p3.y = p2.y - len * sin(angle - M_PI / 6);
			draw_tree(env, p2, p3, angle - M_PI / 6);
		}
		(env->nn)--;
	}
}

void	tree(t_env *env)
{
	t_point	p1;
	t_point	p2;

	clear_img(env);
	env->nn = 0;
	p1.x = WIN_SIZE / 2;
	p1.y = WIN_SIZE * 3 / 4;
	p2.x = WIN_SIZE / 2;
	p2.y = p1.y - line_len(0);
	draw_tree(env, p1, p2, M_PI / 2);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}

void	init_tree(t_env *env)
{
	env->n = 3;
	env->f = &tree;
	env->rainbow = 0;
}
