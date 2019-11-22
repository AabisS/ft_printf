/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_pourcentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:36:04 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/22 11:09:43 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static void	print_for_pourcentage(t_type *str)
{
	int tmp;

	tmp = 0;
	if (str->first)
	{
		tmp = str->first - 1;
		if (str->fless)
		{
			ft_putchar_fd('%', 1, str);
			print(' ', tmp, str);
		}
		else if (!str->fless)
		{
			str->fzero ? print('0', tmp, str) : print(' ', tmp, str);
			ft_putchar_fd('%', 1, str);
		}
	}
	else
		ft_putchar_fd('%', 1, str);
}

void		conv_for_pourcentage(t_type *str)
{
	print_for_pourcentage(str);
}
