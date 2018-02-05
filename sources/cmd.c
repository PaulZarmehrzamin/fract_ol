/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:19:00 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/16 22:33:32 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	print_frame(t_env *env, t_point p, int n, int l)
{
	int		x;
	int		y;

	x = 0;
	while (x < l)
	{
		y = 0;
		while (y < (n * 17 + 7))
		{
			if (x >= 1 && x <= (l - 2) && y >= 1 && y <= (n * 17 + 5))
				mlx_pixel_put(env->mlx, env->win, p.x + x, p.y + y, FRM_COLOR);
			else
				mlx_pixel_put(env->mlx, env->win, p.x + x, p.y + y, CMD_COLOR);
			y++;
		}
		x++;
	}
}

void	print_cmd_1(t_env *env)
{
	t_point	p;
	int		m;

	p.x = 0;
	p.y = 0;
	print_frame(env, p, 6, 180);
	mlx_string_put(env->mlx, env->win, 5, 0, TITLE_COLOR, "COMMANDS");
	mlx_string_put(env->mlx, env->win, 5, 17, CMD_COLOR, "esc) quit");
	mlx_string_put(env->mlx, env->win, 5, 34, CMD_COLOR, "  H) hide menu");
	mlx_string_put(env->mlx, env->win, 5, 51, CMD_COLOR, "+/-) precision");
	mlx_string_put(env->mlx, env->win, 5, 68, CMD_COLOR, "  C) toggle color");
	mlx_string_put(env->mlx, env->win, 5, 85, CMD_COLOR, "  V) switch color");
	m = WIN_SIZE - 160;
	p.x = m;
	print_frame(env, p, 9, 160);
	mlx_string_put(env->mlx, env->win, m + 5, 0, TITLE_COLOR, "FRACTALS");
	mlx_string_put(env->mlx, env->win, m + 5, 17, CMD_COLOR, "1) julia");
	mlx_string_put(env->mlx, env->win, m + 5, 34, CMD_COLOR, "2) mandelbrot");
	mlx_string_put(env->mlx, env->win, m + 5, 51, CMD_COLOR, "3) tricorn");
	mlx_string_put(env->mlx, env->win, m + 5, 68, CMD_COLOR, "4) burning ship");
	mlx_string_put(env->mlx, env->win, m + 5, 85, CMD_COLOR, "5) tree");
	mlx_string_put(env->mlx, env->win, m + 5, 102, CMD_COLOR, "6) koch");
	mlx_string_put(env->mlx, env->win, m + 5, 119, CMD_COLOR, "7) square");
	mlx_string_put(env->mlx, env->win, m + 5, 136, CMD_COLOR, "8) cross");
}

void	print_cmd_3(t_env *env, char *str)
{
	t_point	p;

	p.x = 0;
	p.y = WIN_SIZE - 58;
	print_frame(env, p, 3, 260);
	mlx_string_put(env->mlx, env->win, 5, p.y + 0, TITLE_COLOR, str);
	mlx_string_put(env->mlx, env->win, 5, p.y + 17, CMD_COLOR,
			"      arrows) move camera");
	mlx_string_put(env->mlx, env->win, 5, p.y + 34, CMD_COLOR,
			"scroll wheel) zoom");
}

void	print_cmd_julia(t_env *env)
{
	t_point	p;

	p.x = 0;
	p.y = WIN_SIZE - 75;
	print_frame(env, p, 4, 270);
	mlx_string_put(env->mlx, env->win, 5, p.y + 0, TITLE_COLOR, "JULIA");
	mlx_string_put(env->mlx, env->win, 5, p.y + 17, CMD_COLOR,
			"     arrows) move camera");
	if (env->julia.flag)
	{
		mlx_string_put(env->mlx, env->win, 5, p.y + 34, CMD_COLOR,
				"      space) zoom mode");
		mlx_string_put(env->mlx, env->win, 5, p.y + 51, CMD_COLOR,
				" move mouse) set parameter");
	}
	else
	{
		mlx_string_put(env->mlx, env->win, 5, p.y + 34, CMD_COLOR,
				"      space) set parameter");
		mlx_string_put(env->mlx, env->win, 5, p.y + 51, CMD_COLOR,
				"mouse wheel) zoom");
	}
}

void	print_cmd(t_env *env)
{
	print_cmd_1(env);
	if (env->f == &julia)
		print_cmd_julia(env);
	else if (env->f == &mandelbrot)
		print_cmd_3(env, "MANDELBROT");
	else if (env->f == &tricorn)
		print_cmd_3(env, "TRICORN");
	else if (env->f == &burningship)
		print_cmd_3(env, "BURNING SHIP");
}
