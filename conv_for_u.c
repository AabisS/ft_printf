/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:07:57 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/21 13:12:08 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static void	second(t_type *str)
{
	int tmp;

	if (str->fzero && str->fdot)
		tmp = (size_t)str->second - ft_strlen(str->sentence);
	else
		tmp = (size_t)str->second - ft_strlen(str->sentence);
	if (str->u_d < 0)
	{
		print('0', tmp, str);
		ft_putstr_fd(str->sentence, 1, str);
	}
	else
	{
		print('0', tmp, str);
		ft_putstr_fd(str->sentence, 1, str);
	}
}

static void	first(t_type *str)
{
	int tmp;

	tmp = (size_t)str->first - ft_strlen(str->sentence);
	if (str->fless)
	{
		ft_putstr_fd(str->sentence, 1, str);
		!str->fzero ? print(' ', tmp, str) : print('0', tmp, str);
	}
	else
	{
		!str->fzero ? print(' ', tmp, str) : print('0', tmp, str);
		ft_putstr_fd(str->sentence, 1, str);
	}
}

static void	print_for_u(t_type *str)
{
	int tmp;

	if (!str->first && str->fdot && str->second)
		second(str);
	else if (str->first && !str->second && !str->fdot)
		first(str);
	else if (str->first && str->fdot && (str->second || str->remember))
	{
		if (str->u_d >= 0 && str->second)
			tmp = str->first - str->second;
		else
			tmp = (size_t)str->first - ft_strlen(str->sentence);
		if (str->fless)
		{
			second(str);
			!str->fzero ? print(' ', tmp, str) : print('0', tmp, str);
		}
		else
		{
			!str->fzero ? print(' ', tmp, str) : print('0', tmp, str);
			second(str);
		}
	}
	else if (!str->first && !str->second && !str->fdot)
		ft_putstr_fd(str->sentence, 1, str);
}

void		conv_for_u(t_type *str)
{
	str->u_d = va_arg(str->ap, unsigned int);
	str->sentence = ft_uitoa_base(str->u_d, 10, "0123456789");
	parse_flag_x(str);
	print_for_u(str);
}
