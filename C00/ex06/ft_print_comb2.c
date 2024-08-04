/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:22:23 by mdreuich          #+#    #+#             */
/*   Updated: 2024/06/27 14:33:57 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_write(int a, int b)
{
	char	c;

	c = a / 10 + 48;
	write(1, &c, 1);
	c = a % 10 + 48;
	write(1, &c, 1);
	write(1, " ", 1);
	c = b / 10 + 48;
	write(1, &c, 1);
	c = b % 10 +48;
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;

	x = 0;
	while (x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			ft_write(x, y);
			if (x != 98)
				write(1, ", ", 2);
			y++;
		}
		x++;
	}
}
