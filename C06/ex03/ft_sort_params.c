/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:18:16 by mdreuich          #+#    #+#             */
/*   Updated: 2024/07/08 17:48:30 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(char **s1, char **s2)
{
	char	*p;

	p = *s1;
	*s1 = *s2;
	*s2 = p;
}

void	ft_print(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	index;

	i = 1;
	while (i < ac - 1)
	{
		j = 1 + i;
		index = i;
		while (j < ac)
		{
			if (ft_strcmp(av[index], av[j]) > 0)
				index = j;
			j++;
		}
		ft_swap(&av[i], &av[index]);
		i++;
	}
	ft_print(ac, av);
	return (0);
}
