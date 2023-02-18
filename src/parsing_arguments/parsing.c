#include "../../inc/ft_ls.h"

static void parse_directories(t_ls *ls, char **av, int c, int j, int ac)
{
	if (!(ls->directories = malloc(sizeof(char*) * c - 1)))
	{
		perror("malloc");
		exit(ALLOC_ERR);
	}
	// printf("c = %d\n", c);
	// printf("ac = %d\n", ac);

	for (int i = 0; i < c && j <= ac; i++)
	{
		ls->directories[i] = ft_strdup(av[j]);
		// printf("i = %d\n", i);
		j++;
	}
	// printf("j = %d\n", j);
	// printf("\n");

	// for (int i = 0; i < c; i++)
	// {
	// 	printf("i = %d\n", i);
	// 	printf("ls->dir[i] = %s\n", ls->directories[i]);
	// }
}

static void	check_errors(char *arg)
{
	int		index = 0;
	int		count = 0;

	// if (arg[0] == '-' && ft_strlen(arg) == 1)
	// {
	// 	ft_printf("ls: %s: No such file or directory\n", arg);
	// 	// exit(OPENDIR_ERR);
	// }

	while (arg[index])
	{
		if (arg[index] == '-')
			count++;
		index++;
	}

	if (count >= 2)
	{
		if (count == 2 && arg[1] == '-' && arg[2] == '\0')
			;
		else
			error_msg_unrecognized_option(&arg[index-1], count);
	}

	for (int i = 1; arg[i]; i++)
	{
		if (arg[i] != 'a' && arg[i] != 'R' && arg[i] != 'r'
				&& arg[i] != 'l' && arg[i] != 't' && arg[i] != '-')
			error_msg_invalid_option(&arg[i]);
	}
}

static void	parse_options(char *arg, t_ls *ls)
{
	// printf("arg1 = %s\n", arg);
	check_errors(arg);

	for (int i = 1; arg[i]; i++)
	{
		if (arg[i] == 'a')
			ls->dash_a = 1;
		else if (arg[i] == 'R')
			ls->dash_R = 1;
		else if (arg[i] == 'r')
			ls->dash_r = 1;
		else if (arg[i] == 'l')
			ls->dash_l = 1;
		else if (arg[i] == 't')
			ls->dash_t = 1;
	}
	printf("----------------\n");
}

void	parsing(t_ls *ls, int ac, char **av)
{
	int		i = 1;
	int		j = 0;
	int		c = 0;

	while (i < ac && av[i])
	{
		if (av[i][0] == '-' && av[i][1])
		{
			while (i < ac && av[i][0] == '-' && av[i][1])
			{
				parse_options(av[i], ls);
				i++;
			}
		}
		else
		{
			j = i;
			while (i < ac && av[i])
			{
				c++;
				i++;
			}

			parse_directories(ls, av, c, j, ac);
		}
	}
	printf("\nls->dash_a = %d\n", ls->dash_a);
	printf("ls->dash_R = %d\n", ls->dash_R);
	printf("ls->dash_r = %d\n", ls->dash_r);
	printf("ls->dash_l = %d\n", ls->dash_l);
	printf("ls->dash_t = %d\n", ls->dash_t);
	for (int i = 0; i < c; i++)
	{
		// printf("i = %d\n", i);
		printf("ls->dir[i] = %s\n", ls->directories[i]);
	}
}
