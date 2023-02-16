#include "../../inc/ft_ls.h"

static void	parse_options(char *arg, t_ls *ls)
{
	(void)ls;
	int		index = 0;
	int		count = 0;

	while (arg[index])
	{
		if (arg[index] == '-')
			count++;
		index++;
	}
	// printf("arg[i] = %c\n", arg[index - 1]);

	if (count >= 2)
		error_msg_unrecognized_option(&arg[index-1], count);

	for (int i = 1; arg[i]; i++)
	{
		if (arg[i] != 'a' && arg[i] != 'R' && arg[i] != 'r'
				&& arg[i] != 'l' && arg[i] != 't' && arg[i] != '-')
			error_msg_invalid_option(&arg[i]);
	}
	// printf("%s\n", arg);
}

void	parsing(t_ls *ls, int ac, char **av)
{
	int i = 1;
	(void)ls;

	while (i < ac && av[i])
	{
		if (av[i][0] == '-')
		{
			while (i < ac && av[i][0] == '-')
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
				// printf("arg2 : [%s]\n", av[i]);
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
