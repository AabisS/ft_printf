/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:30:39 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/12 11:48:08 by fmarckma         ###   ########.fr       */
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
			ft_putchar_fd(str->car, 1);
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
		}
		if (!str->fless)
		{
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
			ft_putchar_fd(str->car, 1);
		}
	}
	else if (!str->fless && !str->fzero && !str->fstar && !str->fdot)
		ft_putchar_fd(str->car, 1);
}
void    conv_for_c(t_type *str)
{
	str->car = va_arg(str->ap, int);
	print_for_c(str);
}
