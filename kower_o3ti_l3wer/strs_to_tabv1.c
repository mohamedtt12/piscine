#include <stdio.h>
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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_allocate(char *str, int size)
{
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	return (str);
}

void	ft_free(t_stock_str **array, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		free(array[i]->str);
		free(array[i]->copy);
		i++;
	}
	free(*array);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *array;
	int	i;

	i = 0;
	array = malloc(sizeof(t_stock_str) * ac + 1);
	if (!array)
		return (NULL);
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = ft_allocate(array[i].str, ft_strlen(av[i]));
		array[i].str = ft_strcpy(array[i].str, av[i]);
		array[i].copy = ft_allocate(array[i].copy, ft_strlen(av[i]));
		array[i].copy = ft_strcpy(array[i].copy, av[i]);
		i++;
	}
	array[i].size = 0;
	array[i].str = ft_allocate(array[i].str, 1);
	array[i].str = NULL;
	//ft_free(&array, ac);
	return (array);
}

int main(void)
{
	char *av[]={"Mohamed", "Anass", "Louchame", "Rafik"};
	t_stock_str *array;
	array = ft_strs_to_tab(4, av);
	printf("%d", array[0].size);
	return (0);
}
