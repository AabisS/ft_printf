/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:07:57 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/08 15:47:40 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print_for_d_i(t_type *str)
{
	int tmp;
	int tmp2;
	if (str->first && !str->second)
	{	
		tmp = str->first - ft_strlen(str->sentence);
		if (str->fless)
		{
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
			ft_putstr_fd(str->sentence, 1);
		}
	}
	if (!str->first && (str->fdot || str->fzero) && str->second)
	{
		tmp = str->second - ft_strlen(str->sentence);
		if (tmp > 0 && !str->fless)
			while (tmp--)
				ft_putchar_fd('0', 1);
		ft_putstr_fd(str->sentence, 1);
	}
	if (str->first && str->second && str->fdot)
	{
		if (str->second > ft_strlen(str->sentence))
			tmp = str->first - str->second;
		tmp2 = str->second - ft_strlen(str->sentence);
		if (str->fless)
		{
			if (tmp2 > 0)
				while (tmp2--)
					ft_putchar_fd('0', 1);
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
				if (str->remember)
				ft_putchar_fd('-', 1);
				while (tmp2--)
					ft_putchar_fd('0', 1);
			}
			ft_putstr_fd(str->sentence, 1);
		}
	}
}

void	conv_for_d(t_type *str)
{
	str->d_i = va_arg(str->ap, int);
	str->sentence = ft_itoa(str->d_i);
	if (str->sentence[0] == '-')
	{
		str->remember = 1;
		str->sentence = &str->sentence[1];
		if (str->fdot || str->fzero)
			str->first--;
	}
	if (str->second < 0)
		str->second = 0;
	print_for_d_i(str);
}
