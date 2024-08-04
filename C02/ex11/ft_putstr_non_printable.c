/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:27:50 by mdreuich          #+#    #+#             */
/*   Updated: 2024/06/30 19:37:40 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hexa;

	hexa = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (ft_str_is_printable(str[i]))
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hexa[str[i] / 16], 1);
			write(1, &hexa[str[i] % 16], 1);
		}
		i++;
	}
}
