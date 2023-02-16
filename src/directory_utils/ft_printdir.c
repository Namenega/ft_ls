#include "../../inc/ft_ls.h"

void	ft_printdir(char *s)
{
	DIR *dir;
	struct dirent *entry;

	if (!s)
		//TODO
		//implement
		exit(1);

	dir = opendir(s);
	if (!dir)
	{
		perror("opendir");
		exit(1);
	}

	while ((entry = readdir(dir)))
		ft_printf("%s\n", entry->d_name);

	closedir(dir);
}
