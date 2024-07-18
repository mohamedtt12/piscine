/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hraba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:40:29 by hraba             #+#    #+#             */
/*   Updated: 2024/06/30 21:40:31 by hraba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_gap(int x, int y);
void	print_hor(int x); // adding prototypes

/*
- if either x or y are negative or equal 0,
program will print newline and stop
- If conditions are met for middle part ( gap ) it will print
- if y dimension is bigger than 1, we print the horizontal letters again
*/

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
		print_hor(x);
}

/*
- we print 'A' first of all,
- we make a loop to print 'B' if i is still smaller than x,
if condition isn't met 'B' will not be printed
- we print 'C' if x is more than 1 column
*/

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
		ft_putchar('C');
	ft_putchar('\n');
}

/*
- Function to print the middle section
- Function will print 'B', and only print spaces and
last 'B' if conditions are met
- j, the variable for we increment to print spaces,
stops before the col of last character (x - 2)
- If the x = 1 only 'B' will be printed, once
- Variable i stops in y - 1 to leave a line for another print_horizontal
- Function is given y - 1, then another y - 1 (y - 2) to leave a line 
for the second horizontal letters
*/

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
