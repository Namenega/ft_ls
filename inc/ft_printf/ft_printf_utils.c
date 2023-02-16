/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:14:06 by Nathan            #+#    #+#             */
/*   Updated: 2020/02/24 16:04:21 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar_p(char c)
{
	write(1, &c, 1);
}

void		ft_putstr_p(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_p(s[i]);
		i++;
	}
}

void		ft_putstrn_p(char *s, int n)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && i < n)
	{
		ft_putchar_p(s[i]);
		i++;
	}
}

int			ft_isdigit_p(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
