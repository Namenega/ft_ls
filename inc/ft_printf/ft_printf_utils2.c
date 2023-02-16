/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:49:39 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/24 16:35:35 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_check_width_prec(t_flag flag)
{
	if (flag.width < 0)
	{
		flag.width *= -1;
		flag.minus = 1;
		flag.zero = 0;
	}
	if (flag.prec < 0)
		flag.prec = -1;
	return (flag);
}

void		ft_putnbr_p(long long n, int p, int len, t_flag flag)
{
	long int	nbr;
	long int	div;
	long int	mod;

	nbr = n;
	if (p == -1 && flag.width)
		p = (nbr >= 0) ? flag.width : flag.width - 1;
	if (nbr < 0)
	{
		ft_putchar_p('-');
		nbr *= -1;
		len--;
	}
	if (flag.prec != -1 ||
		(flag.width > ft_len(n) && flag.prec == -1 && flag.zero))
		while (p > len)
		{
			ft_putchar_p('0');
			p--;
		}
	mod = nbr % 10;
	div = nbr / 10;
	if (div)
		ft_putnbr_p(div, p, len, flag);
	ft_putchar_p(mod + '0');
}

int			ft_hex(unsigned long int n)
{
	if (n >= 16)
		return (ft_hex(n / 16) + 1);
	return (1);
}

void		ft_space(t_flag flag, int n, int m)
{
	int		i;

	i = -1;
	while (++i < flag.width - n - m)
		ft_putchar_p(' ');
}

void		ft_putnbrbase_p(unsigned long n, char *base, int len, t_flag flag)
{
	long long int	div;
	long long int	mod;

	if (flag.prec != -1)
		while (flag.prec > len)
		{
			ft_putchar_p('0');
			flag.prec--;
		}
	if (flag.prec == -1 && flag.width >= ft_hex(n) && flag.zero)
		while (flag.width > len)
		{
			ft_putchar_p('0');
			flag.width--;
		}
	mod = n % 16;
	div = n / 16;
	if (div)
		ft_putnbrbase_p(div, base, len, flag);
	ft_putchar_p(base[mod]);
}
