/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdreuich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:11:56 by mdreuich          #+#    #+#             */
/*   Updated: 2024/06/27 20:21:50 by mdreuich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int*a, int*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	m;
	int	n;

	m = 0;
	n = size - 1;
	while (m < n)
	{
		ft_swap(&tab[m], &tab[n]);
		m++;
		n--;
	}
}
