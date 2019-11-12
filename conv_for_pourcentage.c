/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_pourcentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:50:58 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/12 12:40:37 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void    print_for_pourcentage(t_type *str)
{
	int tmp;

	tmp = 0;
	if (str->first)
	{	
		tmp = str->first - 1;
		if (str->fless)
		{
			ft_putchar_fd('%', 1);
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
		}
		if (!str->fless)
		{
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
			ft_putchar_fd('%', 1);
		}
	}
	else
		ft_putchar_fd('%', 1);
}
void    conv_for_pourcentage(t_type *str)
{
	print_for_pourcentage(str);
}
