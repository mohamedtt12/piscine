/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <mdreuich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:10:49 by mdreuich          #+#    #+#             */
/*   Updated: 2024/07/08 21:38:04 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_check_errors(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 32 || str[i] == 127)
			return (0);
		i++;
	}
	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_to_base(unsigned int nbr, char *base)
{
	unsigned int	result;
	unsigned int	len;

	len = ft_strlen(base);
	result = 0;
	result = nbr / len ;
	if (result)
		ft_to_base(result, base);
	write(1, &base[nbr % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) <= 1)
		return ;
	while (base[i] != '+' && base[i] != '-' && base[i] != '\0')
		i++;
	if (base[i] == '+' || base[i] == '-')
		return ;
	else if (!ft_check_errors(base))
		return ;
	else if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_to_base((unsigned int)2147483648, base);
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_to_base((unsigned int)-nbr, base);
	}
	else
		ft_to_base((unsigned int)nbr, base);
}
