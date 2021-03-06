/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:16:59 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/16 19:17:57 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>

void	get_point4(t_env *env, int x, int y)
{
	t_cmplx	c;
	t_cmplx	z;
	double	tmp;
	int		color;

	c.x = env->julia.origin.x + x * env->julia.zoom / WIN_SIZE;
	c.y = env->julia.origin.y + y * env->julia.zoom / WIN_SIZE;
	z.x = env->julia.z0.x;
	z.y = env->julia.z0.y;
	env->nn = 0;
	while (env->nn < env->n && (z.x * z.x + z.y * z.y) < 16)
	{
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = tmp;
		(env->nn)++;
	}
	if (env->nn != env->n)
	{
		color = get_color(env->nn, env->color, env->rainbow);
		img_pixel_put(env, x, y, color);
	}
}

void	burningship(t_env *env)
{
	int		x;
	int		y;

	clear_img(env);
	x = 0;
	while (x < WIN_SIZE)
	{
		y = 0;
		while (y < WIN_SIZE)
		{
			get_point4(env, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}

void	init_burningship(t_env *env)
{
	env->n = 15;
	env->f = &burningship;
	env->rainbow = 0;
	env->julia.z0.x = 0;
	env->julia.z0.y = 0;
	env->julia.origin.x = -3.5;
	env->julia.origin.y = -3;
	env->julia.zoom = 6;
	env->julia.flag = 0;
}
