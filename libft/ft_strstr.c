/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:16:33 by pzarmehr          #+#    #+#             */
/*   Updated: 2016/11/17 15:33:01 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*xb;
	char	*xl;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		if (*big == *little)
		{
			xb = (char *)big + 1;
			xl = (char *)little + 1;
			while (*xb && *xl && *xb == *xl)
			{
				++xb;
				++xl;
			}
			if (!*xl)
				return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
