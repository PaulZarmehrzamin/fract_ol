/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:12:40 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/16 14:55:26 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	fill_square(t_env *env, int x, int y, int c)
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

void	ft_square(t_env *env, int x, int y, int c)
{
	if (env->nn < env->n && c > 0)
	{
		fill_square(env, x + c / 3, y + c / 3, c / 3);
		(env->nn)++;
		ft_square(env, x, y, c / 3);
		ft_square(env, x + c / 3, y, c / 3);
		ft_square(env, x + c * 2 / 3, y, c / 3);
		ft_square(env, x, y + c / 3, c / 3);
		ft_square(env, x + c * 2 / 3, y + c / 3, c / 3);
		ft_square(env, x, y + c * 2 / 3, c / 3);
		ft_square(env, x + c / 3, y + c * 2 / 3, c / 3);
		ft_square(env, x + c * 2 / 3, y + c * 2 / 3, c / 3);
		(env->nn)--;
	}
}

void	square(t_env *env)
{
	clear_img(env);
	env->nn = 0;
	ft_square(env, 0, 0, WIN_SIZE);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
}

void	init_square(t_env *env)
{
	env->n = 4;
	env->f = &square;
	env->rainbow = 1;
}
