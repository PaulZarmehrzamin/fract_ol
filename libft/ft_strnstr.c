/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:46:14 by pzarmehr          #+#    #+#             */
/*   Updated: 2016/11/17 15:49:32 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*xb;
	char	*xl;
	size_t	xlen;

	if (!*little)
		return ((char *)big);
	while (*big && len--)
	{
		if (*big == *little)
		{
			xb = (char *)big + 1;
			xl = (char *)little + 1;
			xlen = len;
			while (*xb && *xl && *xb == *xl && xlen--)
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
