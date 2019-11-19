/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:30:39 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/19 15:32:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void    print_for_c(t_type *str)
{
	int tmp;

	if (str->first)
	{	
		tmp = str->first - 1;
		if (str->fless)
		{
			ft_putchar_fd(str->car, 1, str);
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1, str);
		}
		if (!str->fless)
		{
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1, str);
			ft_putchar_fd(str->car, 1, str);
		}
	}
	else if (!str->first)
		ft_putchar_fd(str->car, 1, str);
}

static void	parse_flag(t_type *str)
{
	if (str->fdot)
		str->fless = 1;
}

void    conv_for_c(t_type *str)
{
	str->car = va_arg(str->ap, int);
	print_for_c(str);
}
