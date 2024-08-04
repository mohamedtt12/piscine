/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:40:38 by mdreuich          #+#    #+#             */
/*   Updated: 2024/07/03 23:14:13 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		result;
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			write(1, "147483648", 9);
		}
		else
			ft_putnbr(nb * (-1));
	}
	else
	{
		result = nb / 10;
		if (result)
			ft_putnbr(result);
		c = nb % 10 + 48;
		write(1, &c, 1);
	}
}
