#include "../inc/ft_ls.h"

void	error_msg_unrecognized_option(char *message, int count)
{
	char	*dash;
	int		i = 0;

	// printf("msg = %s\n", message);

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
	// printf("dash = [%s]\n", dash);
	// printf("message = %s\n", message);
	
	ft_putstr_fd("ls: unrecognized option `", 1);
	ft_putstr_fd(dash, 1);
	if (ft_strncmp(message, "-", 1) != 0)
		ft_putstr_fd(message, 1);
	write(1, "'\n", 2);
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
