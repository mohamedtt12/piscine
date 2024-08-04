/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 21:42:52 by mdreuich          #+#    #+#             */
/*   Updated: 2024/07/08 22:16:33 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*t;
	int	i;
	int	size;

	if (min >= max)
		return (0);
	size = max - min;
	t = (int *)malloc(sizeof(int) * size);
	if (t == NULL)
		return (0);
	i = 0;
	while (min < max)
	{
		t[i] = min;
		i++;
		min++;
	}
	return (t);
}
