/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:26:04 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/16 22:35:29 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	draw_cross(t_env *env, int x, int y, int c)
{
	int		i;
	int		j;
	int		color;

	color = get_color(env->nn, env->color, env->rainbow);
	i = 0;
	while (i < c)
	{
		j = 0;
		while (j < c)
		{
			img_pixel_put(env, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_cross(t_env *env, int x, int y, int c)
{
	if (env->nn < env->n && c / 3 > 0)
	{
		(env->nn)++;
		ft_cross(env, x, y, c / 3);
		ft_cross(env, x + c * 2, y, c / 3);
		ft_cross(env, x + c, y + c, c / 3);
		ft_cross(env, x, y + c * 2, c / 3);
		ft_cross(env, x + c * 2, y + c * 2, c / 3);
		(env->nn)--;
	}
	else
	{
		draw_cross(env, x, y, c);
		draw_cross(env, x + c * 2, y, c);
		draw_cross(env, x + c, y + c, c);
		draw_cross(env, x, y + c * 2, c);
		draw_cross(env, x + c * 2, y + c * 2, c);
	}
}

void	cross(t_env *env)
{
	clear_img(env);
	env->nn = 0;
	ft_cross(env, 0, 0, WIN_SIZE / 3);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}

void	init_cross(t_env *env)
{
	env->n = 3;
	env->f = &cross;
	env->rainbow = 1;
}
