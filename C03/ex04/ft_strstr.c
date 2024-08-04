/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:18:12 by mdreuich          #+#    #+#             */
/*   Updated: 2024/07/03 00:27:39 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*p;
	char	*q;

	i = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		p = str + i;
		q = to_find;
		while (*p == *q && *q)
		{
			p++;
			q++;
		}
		if (!*q)
			return (str + i);
		i++;
	}
	return (0);
}
