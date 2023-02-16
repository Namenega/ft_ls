#include "../inc/ft_ls.h"

int main(int ac, char **av)
{
	t_ls	*ls;

	if (ac < 2) {
		printf("Usage: %s <directory>\n", av[0]);
		return 1;
	}

	if (!(ls = malloc(sizeof(t_ls))))
	{
		perror("malloc");
		exit(1);
	}



	ft_printdir(av[1]);

	free(ls);
	return(0);
}
