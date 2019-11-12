/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:07:57 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/11 16:27:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print_for_x(t_type *str)
{
	int tmp;
	int tmp2;
	
	tmp = 0;
	tmp2 = 0;
	if (str->first && !str->second && !str->fzero)
	{	
		tmp = str->first - ft_strlen(str->sentence);
		if (str->fless)
		{
			if (str->d_i < 0)
				ft_putchar_fd('-', 1);
			ft_putstr_fd(str->sentence, 1);
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
		}
		//pour largeur positif
		if (!str->fless)
		{
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
			if (str->d_i < 0)
				ft_putchar_fd('-', 1);
			ft_putstr_fd(str->sentence, 1);
		}
	}
	// si precision mais pas largeur
	if (!str->first && (str->fdot || str->fzero) && str->second)
	{
		tmp = str->second - ft_strlen(str->sentence);
		if (tmp > 0 && !str->fless)
		{	
			if (str->d_i < 0)
				ft_putchar_fd('-', 1);
			while (tmp--)
				ft_putchar_fd('0', 1);
		}
		ft_putstr_fd(str->sentence, 1);
	}
	else if (str->first && str->fzero && !str->second)
	{
		tmp = str->first - ft_strlen(str->sentence);
		if (tmp > 0 && !str->fless)
		{	
			if (str->d_i < 0)
				ft_putchar_fd('-', 1);
			while (tmp--)
				ft_putchar_fd('0', 1);
		}
		ft_putstr_fd(str->sentence, 1);
	}
	if (str->first && str->second && str->fdot)
	{
		if (str->second > ft_strlen(str->sentence))
			tmp = str->first - str->second;
		else
			tmp = str->first - ft_strlen(str->sentence);
		tmp2 = str->second - ft_strlen(str->sentence);
		if (str->fless)
		{
			if (tmp2 > 0)
			{	
				if (str->d_i < 0)
					ft_putchar_fd('-', 1);
				while (tmp2--)
					ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(str->sentence, 1);
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
		}
		else if (!str->fless)
		{
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
			if (tmp2 > 0)
			{	
				if (str->d_i < 0)
					ft_putchar_fd('-', 1);
				while (tmp2--)
					ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(str->sentence, 1);
		}
	}
	if (!str->first && !str->second)
		ft_putstr_fd(str->sentence, 1);
}

void	conv_for_x(t_type *str)
{
	str->d_i = va_arg(str->ap, int);
	if (str->second < 0)
		str->second = 0;
	if (!str->d_i)
		str->sentence = ft_strdup("0");
	else
		str->sentence = ft_itoa_base(str->d_i, "0123456789abcdef");
	if (str->fdot && !str->second && str->remember && !str->d_i)
	{
		str->sentence = ft_strdup(" ");
		str->fdot = 0;
		str->fzero = 0;
	}
	if (str->sentence[0] == '-')
	{
		str->sentence = &str->sentence[1];
		if (str->fdot || str->fzero)
			str->first--;
	}
	print_for_x(str);
}
