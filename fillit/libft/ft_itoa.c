/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 14:28:47 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/04/21 15:05:49 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n, int len)
{
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char			*result;
	int				len;
	unsigned int	ui;

	len = n < 0 ? 2 : 1;
	len = count(n, len);
	ui = n < 0 ? -n : n;
	if (!(result = ft_memalloc(len + 1)))
		return (NULL);
	result[len--] = '\0';
	while (len >= 0)
	{
		result[len--] = (ui % 10) + '0';
		ui /= 10;
	}
	if (result[0] == '0' && result[1])
		result[0] = '-';
	return (result);
}
