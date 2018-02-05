/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:08:03 by pzarmehr          #+#    #+#             */
/*   Updated: 2016/12/11 11:27:51 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static	void	nbr_len(int n, size_t *len, int *power_ten)
{
	*len = 2;
	if (n >= 0)
	{
		*len = 1;
		n = -n;
	}
	*power_ten = 1;
	while (n / *power_ten < -9)
	{
		*power_ten *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	int			power_ten;
	size_t		i;

	nbr_len(n, &len, &power_ten);
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	if (n > 0)
		n = -n;
	while (power_ten >= 1)
	{
		str[i++] = -(n / power_ten % 10) + '0';
		power_ten /= 10;
	}
	str[len] = '\0';
	return (str);
}
