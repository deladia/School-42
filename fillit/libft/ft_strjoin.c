/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 11:36:43 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/05/12 16:24:06 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*str;
	size_t	size;

	if (s1 && s2)
		size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	else if (s1)
		size = ft_strlen((char *)s1);
	else if (s2)
		size = ft_strlen((char *)s2);
	else
		return (NULL);
	if ((size + 1 == 0) || !(str = ft_memalloc(size + 1)))
		return (NULL);
	if (s1 && s2)
	{
		str = ft_strcpy(str, ((char *)s1));
		str = ft_strcat(str, ((char *)s2));
	}
	else if (s1)
		str = ft_strcpy(str, ((char *)s1));
	else if (s2)
		str = ft_strcpy(str, ((char *)s2));
	return (str);
}
