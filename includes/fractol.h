/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:12:27 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/16 21:46:42 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_SIZE 729
# define CMD_COLOR 0x00009900
# define TITLE_COLOR 0x00FFFFFF
# define FRM_COLOR 0x00000000

typedef	struct			s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}						t_img;

typedef	struct			s_point
{
	int		x;
	int		y;
}						t_point;

typedef	struct			s_cmplx
{
	double	x;
	double	y;
}						t_cmplx;

typedef	struct			s_julia
{
	t_cmplx	z0;
	t_cmplx	origin;
	double	zoom;
	int		flag;
}						t_julia;

typedef	struct s_env	t_env;

struct					s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		cmd;
	int		color;
	int		rainbow;
	void	(*f)(t_env *);
	int		n;
	int		nn;
	t_julia	julia;
};

void					init_img(t_env *env);
void					clear_img(t_env *env);
void					img_pixel_put(t_env *env, int x, int y, int color);
int						get_color(int n, int c, int x);

void					julia(t_env *env);
void					init_julia(t_env *env);

void					mandelbrot(t_env *env);
void					init_mandelbrot(t_env *env);

void					tricorn(t_env *env);
void					init_tricorn(t_env *env);

void					burningship(t_env *env);
void					init_burningship(t_env *env);

void					tree(t_env *env);
void					init_tree(t_env *env);

void					koch(t_env *env);
void					init_koch(t_env *env);

void					square(t_env *env);
void					init_square(t_env *env);

void					cross(t_env *env);
void					init_cross(t_env *env);

void					print_cmd(t_env *env);
int						expose_hook(t_env *env);
int						key_hook(int keycode, t_env *env);
int						motion_hook(int x, int y, t_env *env);
int						mouse_hook(int button, int x, int y, t_env *env);

#endif
