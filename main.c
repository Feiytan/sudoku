#include "sudoku.h"
#include "../libft/libft.h"
#include "stdio.h"

int		check_column(char **argv, int y, int x, char c)
{
	int i;

	i = 0;
	if (c == '.')
		return (1);
	while(y)
	{
		if (argv[y--][x] == c)
		i++;
	}
	if (i > 1)
		return (0);
	else
		return (1);
}

int		check_len(int y, char **argv)
{
	int x;

	x = 0;
	while (argv[y][x])
	{
		if ((argv[y][x] < '1' || argv[y][x] > '9') && argv[y][x] != '.')
			error("Value");
		check_column(argv, y, x, argv[y][x]);
			error("column");
		x++;
	}
	return (x);
}

void check_tab(int argc, char **argv)
{
	if (argc-- != 10)
		error("Erreur\n");
	while (argc)
		if (check_len(argc--, argv) != 9)
			error("len");
}

void	print_tab(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	print_tab(argc, argv);
	check_tab(argc, argv);
	return (0);
}
