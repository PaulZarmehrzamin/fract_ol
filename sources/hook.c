/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:41:02 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/16 22:34:29 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	init_fract(int keycode, t_env *env)
{
	if (keycode == 83)
		init_julia(env);
	else if (keycode == 84)
		init_mandelbrot(env);
	else if (keycode == 85)
		init_tricorn(env);
	else if (keycode == 86)
		init_burningship(env);
	else if (keycode == 87)
		init_tree(env);
	else if (keycode == 88)
		init_koch(env);
	else if (keycode == 89)
		init_square(env);
	else if (keycode == 91)
		init_cross(env);
}

void	move_cam(int keycode, t_env *env)
{
	if (keycode == 123)
		env->julia.origin.x -= env->julia.zoom / 8;
	else if (keycode == 124)
		env->julia.origin.x += env->julia.zoom / 8;
	else if (keycode == 125)
		env->julia.origin.y += env->julia.zoom / 8;
	else if (keycode == 126)
		env->julia.origin.y -= env->julia.zoom / 8;
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	else if (keycode >= 83 && keycode <= 91)
		init_fract(keycode, env);
	else if (keycode == 69)
		(env->n)++;
	else if (keycode == 78 && env->n > 0)
		(env->n)--;
	else if (keycode == 4)
		env->cmd = !(env->cmd);
	else if (keycode == 8)
		env->color = !(env->color);
	else if (keycode == 9)
		env->rainbow = (env->rainbow + 1) % 7;
	else if (keycode == 49 && env->f == &julia)
		env->julia.flag = !(env->julia.flag);
	else if (keycode >= 123 && keycode <= 126)
		move_cam(keycode, env);
	expose_hook(env);
	return (0);
}

int		motion_hook(int x, int y, t_env *env)
{
	if (env->f == &julia && env->julia.flag)
	{
		env->julia.z0.x = 4.0 * x / WIN_SIZE - 2.0;
		env->julia.z0.y = 4.0 * y / WIN_SIZE - 2.0;
		expose_hook(env);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *env)
{
	if (x >= 0 && y >= 0 && x <= WIN_SIZE && y <= WIN_SIZE)
	{
		if (button == 1 || button == 5)
		{
			if (!env->julia.flag)
			{
				env->julia.origin.x += x * env->julia.zoom / 2 / WIN_SIZE;
				env->julia.origin.y += y * env->julia.zoom / 2 / WIN_SIZE;
				env->julia.zoom /= 2;
			}
		}
		else if (button == 2 || button == 4)
		{
			if (!env->julia.flag)
			{
				env->julia.origin.x -= x * env->julia.zoom / WIN_SIZE;
				env->julia.origin.y -= y * env->julia.zoom / WIN_SIZE;
				env->julia.zoom *= 2;
			}
		}
	}
	expose_hook(env);
	return (0);
}
