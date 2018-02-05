/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:04:58 by pzarmehr          #+#    #+#             */
/*   Updated: 2016/12/11 09:10:17 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (!ft_isdigit(*str))
	{
		if (*str == '-')
			sign = -1;
		if (*str == '+' || *str == '-')
			str++;
	}
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + sign * (*str - '0');
		str++;
	}
	return (nbr);
}
