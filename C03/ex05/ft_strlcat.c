/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:53:14 by mdreuich          #+#    #+#             */
/*   Updated: 2024/07/03 20:15:49 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	s_len;
	unsigned int	d_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (size <= d_len)
		return (s_len + size);
	if (size > d_len)
	{
		i = d_len;
		j = 0;
		size = size - 1 - d_len;
		while (src[j] && size)
		{
			dest[i] = src[j];
			j++;
			i++;
			size--;
		}
		dest[i] = '\0';
	}
	return (d_len + s_len);
}
