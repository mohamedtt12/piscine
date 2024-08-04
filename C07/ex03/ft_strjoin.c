/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:54:53 by mdreuich          #+#    #+#             */
/*   Updated: 2024/07/15 00:31:07 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_concatenate(int size, char **strs, char *result, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0 ;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			result[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			result[k] = sep[j];
			k++;
			j++;
		}
		i++;
	}
	result[k] = '\0';
}

int	ft_len_totale(int size, char **strs, char *sep)
{
	int	i;
	int	t_len;
	int	sep_len;

	i = 0;
	t_len = 0;
	sep_len = 0;
	while (i < size)
	{
		t_len += ft_strlen(strs[i]);
		i++;
	}
	sep_len = ft_strlen(sep) * (size - 1);
	t_len += sep_len;
	return (t_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		t_len;
	char	*result;

	if (!size)
	{
		result = (char *)malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	t_len = ft_len_totale(size, strs, sep);
	result = (char *)malloc(sizeof(char) * t_len + 1);
	if (!result)
		return (NULL);
	ft_concatenate(size, strs, result, sep);
	return (result);
}
