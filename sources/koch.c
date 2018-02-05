/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:50:05 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/16 17:46:36 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>

void	draw_line(t_env *env, t_cmplx start, float angle, int len)
{
	int		color;
	int		i;
	int		x;
	int		y;

	color = get_color(env->nn, env->color, env->rainbow);
	i = 0;
	while (i <= len + 1)
	{
		x = start.x + i * cos(angle);
		y = start.y - i * sin(angle);
		img_pixel_put(env, x, y, color);
		i++;
	}
}

void	koch_line(t_env *env, t_cmplx p1, float angle, int len)
{
	t_cmplx	p2;

	if (env->nn < env->n && len > 0)
	{
		(env->nn)++;
		koch_line(env, p1, angle, len / 3);
		p2.x = p1.x + cos(angle) * len / 3;
		p2.y = p1.y - sin(angle) * len / 3;
		koch_line(env, p2, angle + M_PI / 3, len / 3);
		p2.x = p2.x + cos(angle + M_PI / 3) * len / 3;
		p2.y = p2.y - sin(angle + M_PI / 3) * len / 3;
		koch_line(env, p2, angle - M_PI / 3, len / 3);
		p2.x = p1.x + cos(angle) * 2 * len / 3;
		p2.y = p1.y - sin(angle) * 2 * len / 3;
		koch_line(env, p2, angle, len / 3);
		(env->nn)--;
	}
	else
		draw_line(env, p1, angle, len);
}

void	koch(t_env *env)
{
	t_cmplx	p;
	int		len;

	p.x = WIN_SIZE / 5;
	p.y = WIN_SIZE * 3 / 10;
	len = WIN_SIZE * 3 / 5;
	clear_img(env);
	env->nn = 0;
	koch_line(env, p, 0, len);
	p.x = p.x + len;
	koch_line(env, p, -M_PI * 2 / 3, len);
	p.x = p.x + len * cos(-M_PI * 2 / 3);
	p.y = p.y - len * sin(-M_PI * 2 / 3);
	koch_line(env, p, M_PI * 2 / 3, len);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}

void	init_koch(t_env *env)
{
	env->n = 0;
	env->f = &koch;
	env->rainbow = 1;
}
