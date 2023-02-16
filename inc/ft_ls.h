
#ifndef FT_LS
# define FT_LS

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# include <dirent.h> /* opendir, readdir, closedir */

typedef struct	s_ls
{
	int		dash_R;
	int		dash_r;
	int		dash_l;
	int		dash_a;
	int		dash_t;
}				t_ls;

int		main(int ac, char **av);

/*
 * Directory management utils
 */
void	ft_printdir(char *s);

#endif
