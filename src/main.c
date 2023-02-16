#include "../inc/ft_ls.h"

void	error_msg_unrecognized_option(char *message, int count)
{
	char	*dash;
	int		i = 0;

	printf("msg = %s\n", message);
	// printf("count = %d\n", count);

	if (!(dash = malloc(sizeof(char) * count)))
	{
		perror("malloc");
		exit(ALLOC_ERR);
	}

	while (i < count)
	{
		dash[i] = '-';
		i++;
	}
	dash[i] = '\0';
	printf("dash = [%s]\n", dash);
	printf("message = %s\n", message);
	
	// PROBLEME FT_PRINTF !!
	ft_printf("ls: unrecognized option `%s%s'\n", dash, message);
	ft_printf("usage: ls [-Ralrt] [file ...]\n");
	free(dash);
	exit(PARSE_ERR);
}

void	error_msg_invalid_option(char *message)
{
	ft_printf("ls: invalid option -- %s\n", message);
	ft_printf("usage: ls [-Ralrt] [file ...]\n");
	exit(PARSE_ERR);
}

static void	init_struct(t_ls *ls)
{
	if (!(ls = malloc(sizeof(t_ls))))
	{
		perror("malloc");
		exit(ALLOC_ERR);
	}

	ls->dash_a = 0;
	ls->dash_R = 0;
	ls->dash_r = 0;
	ls->dash_l = 0;
	ls->dash_t = 0;

	if (!(ls->directories = malloc(sizeof(char *))))
	{
		perror("malloc");
		exit(ALLOC_ERR);
	}

	for (int i = 0; ls->directories[i]; i++)
		ft_memset(ls->directories[i], 0, 0);
		// ls->directories[i] = NULL;
}

int main(int ac, char **av)
{
	t_ls	*ls = NULL;

	init_struct(ls);

	//parse the command line arguments
	parsing(ls, ac, av);

	//open and read directories
	// ft_printdir(av[1]);

	//use stat() to get info about file (owner, group, ...)

	//implement logic with options



	free(ls);
	return(0);
}
