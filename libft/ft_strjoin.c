/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzarmehr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:53:40 by pzarmehr          #+#    #+#             */
/*   Updated: 2016/12/15 23:28:20 by pzarmehr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (str)
	{
		ft_strcpy(str, s1);
		ft_strcpy(str + l1, s2);
	}
	return (str);
}
