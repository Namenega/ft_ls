#include "../inc/ft_ls.h"

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
