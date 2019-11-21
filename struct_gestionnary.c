/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_gestionnary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:15:28 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/21 12:39:32 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print(char c, int tmp, t_type *str)
{
	if (tmp > 0)
		while (tmp--)
			ft_putchar_fd(c, 1, str);
}

void	initialize_all(t_type *str)
{
	str->fdot = 0;
	str->fless = 0;
	str->fzero = 0;
	str->fstar = 1;
	str->first = 0;
	str->second = 0;
	str->remember = 0;
	str->d_i = 0;
	str->sentence = NULL;
	str->car = 0;
	str->p = NULL;
	str->u_d = 0;
}
