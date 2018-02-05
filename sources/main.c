/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:12:59 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/17 11:00:15 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

int		expose_hook(t_env *env)
{
	(env->f)(env);
	if (env->cmd)
		print_cmd(env);
	return (0);
}

int		exit_hook(t_env *env)
{
	(void)env;
	exit(0);
}

void	print_usage(void)
{
	ft_putstr("Usage : ./fractol [1-8]\n");
	ft_putstr("-> 1 : julia\n");
	ft_putstr("-> 2 : mandelbrot\n");
	ft_putstr("-> 3 : tricorn\n");
	ft_putstr("-> 4 : burning ship\n");
	ft_putstr("-> 5 : tree\n");
	ft_putstr("-> 6 : koch\n");
	ft_putstr("-> 7 : square\n");
	ft_putstr("-> 8 : cross\n");
	exit(1);
}

int		get_fract(char *str)
{
	if (!ft_strcmp(str, "1"))
		return (83);
	else if (!ft_strcmp(str, "2"))
		return (84);
	else if (!ft_strcmp(str, "3"))
		return (85);
	else if (!ft_strcmp(str, "4"))
		return (86);
	else if (!ft_strcmp(str, "5"))
		return (87);
	else if (!ft_strcmp(str, "6"))
		return (88);
	else if (!ft_strcmp(str, "7"))
		return (89);
	else if (!ft_strcmp(str, "8"))
		return (91);
	else
		return (0);
}

int		main(int ac, char **av)
{
	t_env	env;
	int		fract;

	if (ac != 2)
		print_usage();
	if (!(fract = get_fract(av[1])))
		print_usage();
	if (!(env.mlx = mlx_init()))
		ft_error(2, "Error - main.c : mlx_init() failed\n");
	if (!(env.win = mlx_new_window(env.mlx, WIN_SIZE, WIN_SIZE, "fractol")))
		ft_error(3, "Error - main.c : mlx_new_window() failed\n");
	env.cmd = 1;
	env.color = 1;
	init_img(&env);
	key_hook(fract, &env);
	mlx_expose_hook(env.win, &expose_hook, &env);
	mlx_hook(env.win, 17, (1L << 17), &exit_hook, &env);
	mlx_hook(env.win, 2, (1L << 0), &key_hook, &env);
	mlx_hook(env.win, 6, (1L << 6), &motion_hook, &env);
	mlx_mouse_hook(env.win, &mouse_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
