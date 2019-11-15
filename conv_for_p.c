/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 10:53:37 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/15 18:33:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print_for_p(t_type *str)
{
	int tmp;
	int tmp2;
	
	tmp = 0;
	tmp2 = 0;
	if (str->first && !str->second && !str->fzero)
	{	
		tmp = str->first - (ft_strlen(str->sentence) + 2);
		if (str->fless)
		{
			ft_putstr_fd("0x", 1, str);
			ft_putstr_fd(str->sentence, 1, str);
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1, str);
		}
		//pour largeur positif
		if (!str->fless)
		{
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1, str);
			ft_putstr_fd("0x", 1, str);
			ft_putstr_fd(str->sentence, 1, str);
		}
	}
	// si precision mais pas largeur
	if (!str->first && (str->fdot || str->fzero) && str->second)
	{
		tmp = str->second - ft_strlen(str->sentence);
		if (tmp > 0 && !str->fless)
		{	
			ft_putstr_fd("0x", 1, str);
			while (tmp--)
				ft_putchar_fd('0', 1, str);
			tmp = -1;
		}
		else if (tmp != -1)
			ft_putstr_fd("0x", 1, str);
		ft_putstr_fd(str->sentence, 1, str);
	}
	else if (str->first && str->fzero && !str->second)
	{
		tmp = str->first - ft_strlen(str->sentence);
		if (tmp > 0 && !str->fless)
		{	
			ft_putstr_fd("0x", 1, str);
			while (tmp--)
				ft_putchar_fd('0', 1, str);
			tmp = -1;
		}
		else if (tmp != -1)
			ft_putstr_fd("0x", 1, str);
		ft_putstr_fd(str->sentence, 1, str);
	}
	if (str->first && str->second && str->fdot)
	{
		if (str->second > ft_strlen(str->sentence))
			tmp = str->first - str->second - 2;
		else
			tmp = str->first - ft_strlen(str->sentence) - 2;
		tmp2 = str->second - ft_strlen(str->sentence);
		if (str->fless)
		{
			if (tmp2 > 0)
			{	
				ft_putstr_fd("0x", 1, str);
				while (tmp2--)
					ft_putchar_fd('0', 1, str);
				tmp2 = -1;
			}
			else if (tmp2 != -1)
				ft_putstr_fd("0x", 1, str);
			ft_putstr_fd(str->sentence, 1, str);
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1, str);
		}
		else if (!str->fless)
		{
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1, str);
			if (tmp2 > 0)
			{	
				ft_putstr_fd("0x", 1, str);
				while (tmp2--)
					ft_putchar_fd('0', 1, str);
				tmp2 = -1;
			}
			else if (tmp2 != -1)
				ft_putstr_fd("0x", 1, str);
			ft_putstr_fd(str->sentence, 1, str);
		}
	}
	if (!str->first && !str->second && !str->fdot)
	{
		ft_putstr_fd("0x", 1, str);
		ft_putstr_fd(str->sentence, 1, str);
	}
}

void    conv_for_p(t_type *str)
{
	str->p = va_arg(str->ap, void *);
	str->sentence = ft_uitoa_base((__uintmax_t)str->p, 16,  "0123456789abcdef");
	if (str->second < 0)
		str->second = ft_strlen(str->sentence);
	if (str->fdot && !str->second)
	{
		str->fdot = 0;
		str->fzero = 0;
	}
	if (str->sentence[0] == '-')
	{
		str->sentence = &str->sentence[1];
		if (str->fdot || str->fzero)
			str->first--;
	}
	print_for_p(str);
}
