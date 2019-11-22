/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:07:57 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/22 10:07:51 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static void	second(t_type *str)
{
	int tmp;

	if (str->fzero && str->fdot)
		tmp = (size_t)str->second - ft_strlen(ft_itoa(str->d_i));
	else
		tmp = (size_t)str->second - ft_strlen(str->sentence);
	if (str->d_i < 0)
	{
		ft_putchar_fd('-', 1, str);
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

	tmp = (size_t)str->first - ft_strlen(ft_itoa(str->d_i));
	if (str->fless)
	{
		str->d_i ? ft_putnbr_fd(str->d_i, 1, str) :
		ft_putstr_fd(str->sentence, 1, str);
		!str->fzero ? print(' ', tmp, str) : print('0', tmp, str);
	}
	else
	{
		if (str->d_i < 0 && str->fzero)
			ft_putchar_fd('-', 1, str);
		!str->fzero ? print(' ', tmp, str) : print('0', tmp, str);
		if (str->d_i < 0 && str->fzero)
			str->d_i ? ft_putstr_fd(str->sentence, 1, str) :
			ft_putstr_fd(str->sentence, 1, str);
		else
			str->d_i ? ft_putnbr_fd(str->d_i, 1, str) :
			ft_putstr_fd(str->sentence, 1, str);
	}
}

void		print_for_d_i(t_type *str)
{
	if (!str->first && str->fdot && str->second)
		second(str);
	else if (str->first && !str->second && !str->fdot)
		first(str);
	else if (str->first && str->fdot && (str->second || str->remember))
		print_for_d_i2(str);
	else if (!str->first && !str->second && !str->fdot)
		ft_putnbr_fd(str->d_i, 1, str);
}

void		print_for_d_i2(t_type *str)
{
	int tmp;

	if (str->d_i < 0 && str->second)
		tmp = str->first - str->second - 1;
	else if (str->d_i >= 0 && str->second)
		tmp = str->first - str->second;
	else
		tmp = (size_t)str->first - ft_strlen(ft_itoa(str->d_i));
	if (str->fless)
	{
		second(str);
		str->fzero ? print('0', tmp, str) : print(' ', tmp, str);
	}
	else
	{
		if (str->d_i < 0 && str->fzero)
		{
			ft_putchar_fd('-', 1, str);
			str->d_i *= -1;
		}
		str->fzero ? print('0', tmp, str) : print(' ', tmp, str);
		second(str);
	}
}

void		conv_for_d(t_type *str)
{
	str->d_i = va_arg(str->ap, int);
	str->sentence = ft_itoa(str->d_i);
	parse_flag_d(str);
	print_for_d_i(str);
}
