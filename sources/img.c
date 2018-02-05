/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:31:15 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/16 14:50:57 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"

void	img_pixel_put(t_env *env, int x, int y, int color)
{
	int				oct;
	int				addr;
	unsigned int	rgb;
	int				i;

	oct = env->img.bpp / 8;
	addr = x * oct + y * env->img.size_line;
	rgb = mlx_get_color_value(env->mlx, color);
	i = 0;
	while (i < oct)
	{
		env->img.data[addr + i] = rgb >> (8 * i);
		i++;
	}
}

void	init_img(t_env *env)
{
	if (!(env->img.img = mlx_new_image(env->mlx, WIN_SIZE, WIN_SIZE)))
		ft_error(1, "Error - img.c : mlx_new_img() failed\n");
	if (!(env->img.data = mlx_get_data_addr(env->img.img, &(env->img.bpp),
					&(env->img.size_line), &(env->img.endian))))
		ft_error(2, "Error - img.c : mlx_get_data_addr() failed\n");
}

void	clear_img(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img.img);
	init_img(env);
}
