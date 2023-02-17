#include "../../inc/ft_ls.h"

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
		error_msg_unrecognized_option(&arg[index-1], count);

	for (int i = 1; arg[i]; i++)
	{
		if (arg[i] != 'a' && arg[i] != 'R' && arg[i] != 'r'
				&& arg[i] != 'l' && arg[i] != 't' && arg[i] != '-')
			error_msg_invalid_option(&arg[i]);
	}
}

static void	parse_options(char *arg, t_ls *ls)
{
	(void)ls;

	check_errors(arg);

	// printf("arg = %s\n", arg);

	// printf("ls->dash_a = %d", ls->dash_a);
	// printf("ls->dash_R = %d", ls->dash_R);
	// printf("ls->dash_r = %d", ls->dash_r);
	// printf("ls->dash_l = %d", ls->dash_l);
	// printf("ls->dash_t = %d", ls->dash_t);

	// for (int i = 1; arg[i]; i++)
	// {
	// 	if (arg[i] == 'a')
	// 		ls->dash_a = 1;
	// 	else if (arg[i] == 'R')
	// 		ls->dash_R = 1;
	// 	else if (arg[i] == 'r')
	// 		ls->dash_r = 1;
	// 	else if (arg[i] == 'l')
	// 		ls->dash_l = 1;
	// 	else if (arg[i] == 't')
	// 		ls->dash_t = 1;
	// }

	// printf("ls->dash_a = %d", ls->dash_a);
	// printf("ls->dash_R = %d", ls->dash_R);
	// printf("ls->dash_r = %d", ls->dash_r);
	// printf("ls->dash_l = %d", ls->dash_l);
	// printf("ls->dash_t = %d", ls->dash_t);
}

void	parsing(t_ls *ls, int ac, char **av)
{
	int i = 1;
	(void)ls;

	while (i < ac && av[i])
	{
		if (av[i][0] == '-' /*&& av[i][1] != '\0'*/)
		{
			while (i < ac && av[i][0] == '-' /*&& av[i][1] != '\0'*/)
			{
				// printf("arg1 : [%s]\n", av[i]);
				parse_options(av[i], ls);
				i++;
			}
		}
		else
		{
			while (i < ac && av[i])
			{
				printf("arg2 : [%s]\n", av[i]);
				// parse_directories(ls);
				i++;
			}
		}
	}




	// for (int i = 1; av[i]; i++)
	// {
	// 	printf("av[i] = %s\n", av[i]);
	// 	if (av[i][0] == '-')
	// 	{
	// 		// while (av[i][0] == '-')
	// 		for (int j = i; av[j][0] == '-'; j++)
	// 		{
	// 			printf("arg1 : [%s]\n", av[i]);
	// 			// parse_options(ls);
	// 			i = j;
	// 			// j++;
	// 			printf("yo\n");
	// 		}
	// 	}
	// 	else
	// 	{
	// 		while (av[i])
	// 		{
	// 			printf("arg2 : [%s]\n", av[i]);
	// 			// parse_directories(ls);
	// 			i++;
	// 		}
	// 		i--;
	// 	}
	// 	i--;
	// 	printf("\n");
	// }
}
