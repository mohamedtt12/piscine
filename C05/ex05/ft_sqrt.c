/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:20:52 by mdreuich          #+#    #+#             */
/*   Updated: 2024/07/07 16:31:20 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb == 1)
		return (1);
	i = 2;
	while (i <= nb / 2)
	{
		if ((i * i) == nb)
			return (i);
		else
			i++;
	}
	return (0);
}
