#include <stdlib.h>
#include "ft_stock_str.h"
#include <unistd.h>

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
//------------------------------
void    ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void	ft_putnbr(int nb)
{
	int		n;
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			write(1, "147483648", 9);
		}
		else
			ft_putnbr(nb * (-1));
	}
	else
	{
		n = nb / 10;
		if (n != 0)
			ft_putnbr(n);
		c = nb % 10 + 48;
		write(1, &c, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
int main(void)
{
	char *av[]={"Mohamed", "Anass", "Louchame", "Rafik"};
	t_stock_str *array;
	array = ft_strs_to_tab(4, av);
	ft_show_tab(array);

	return (0);
}
