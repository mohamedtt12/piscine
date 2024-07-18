/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hraba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:40:29 by hraba             #+#    #+#             */
/*   Updated: 2024/06/30 21:40:31 by hraba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_gap(int x, int y);
void	print_hor_c(int x);
void	print_hor(int x); // adding prototypes

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		ft_putchar('\n');
		return ;
	}
	print_hor(x);
	print_gap(x, y - 1);
	if (y > 1)
		print_hor_c(x);
}

void	print_hor(int x)
{
	int	i;

	i = 0;
	ft_putchar('A');
	i++;
	while (i < x - 1)
	{
		ft_putchar('B');
		i++;
	}
	if (x > 1)
		ft_putchar('A');
	ft_putchar('\n');
}

void	print_gap(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y - 1)
	{
		ft_putchar('B');
		j = 0;
		while (j < x - 2)
		{
			ft_putchar(' ');
			j++;
		}
		if (x > 1)
			ft_putchar('B');
		ft_putchar('\n');
		i++;
	}
}

void	print_hor_c(int x)
{
	int	i;

	i = 0;
	ft_putchar('C');
	i++;
	while (i < x - 1)
	{
		ft_putchar('B');
		i++;
	}
	if (x > 1)
		ft_putchar('C');
	ft_putchar('\n');
}
