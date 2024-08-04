/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:13:34 by mdreuich          #+#    #+#             */
/*   Updated: 2024/07/15 20:39:00 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	i = 0;
	while (src[i])
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	ft_free(t_stock_str *array, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(array[i].str);
		free(array[i].copy);
		i++;
	}
	free(array);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*array;
	int			i;

	i = 0;
	array = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!array)
		return (NULL);
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = ft_strdup(av[i]);
		array[i].copy = ft_strdup(av[i]);
		if (array[i].str == NULL || array[i].copy == NULL)
		{
			ft_free(array, i);
			return (NULL);
		}
		i++;
	}
	array[i].size = 0;
	array[i].str = NULL;
	array[i].copy = NULL;
	return (array);
}
