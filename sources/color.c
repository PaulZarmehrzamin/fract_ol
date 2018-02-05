/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <pzarmehr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 22:13:04 by pzarmehr          #+#    #+#             */
/*   Updated: 2017/03/16 17:11:48 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int n, int c, int x)
{
	n = n + 7 - x;
	if (c == 1)
		return (0x00FFFFFF);
	if (n % 7 == 0)
		return (0x00FF0000);
	else if (n % 7 == 1)
		return (0x00FF7F00);
	else if (n % 7 == 2)
		return (0x00FFFF00);
	else if (n % 7 == 3)
		return (0x0000FF00);
	else if (n % 7 == 4)
		return (0x000077FF);
	else if (n % 7 == 5)
		return (0x002200FF);
	else
		return (0x009900CC);
}
