#include "../../inc/ft_ls.h"

void	ft_printdir(char *s)
{
	DIR *dir;
	struct dirent *entry;

	if (!s)
	{
		perror("empty_string");
		exit(EMPTY_STRING_ERR);
	}

	dir = opendir(s);
	if (!dir)
	{
		perror(s);
		exit(OPENDIR_ERR);
	}

	while ((entry = readdir(dir)))
		ft_printf("%s\n", entry->d_name);

	closedir(dir);
}
