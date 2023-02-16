
#ifndef FT_LS
# define FT_LS

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# include <dirent.h> /* opendir, readdir, closedir */
# include <sys/stat.h> /* opendir, readdir, closedir */

# define ALLOC_ERR			1
# define OPENDIR_ERR		2
# define EMPTY_STRING_ERR	3
# define PARSE_ERR			4

typedef struct	s_ls
{
	int		dash_R;
	int		dash_r;
	int		dash_l;
	int		dash_a;
	int		dash_t;

	char	**directories;
}				t_ls;

int		main(int ac, char **av);
void	error_msg_invalid_option(char *message);
void	error_msg_unrecognized_option(char *message, int count);

/*
 * Parsing arguments
 */
void	parsing(t_ls *ls, int ac, char **av);

/*
 * Directory management utils
 */
void	ft_printdir(char *s);

#endif
