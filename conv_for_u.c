/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:29:34 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/13 13:39:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print_for_u(t_type *str)
{
	int tmp;
	int tmp2;
	
	//printf("first : %d\n", str->first);
	//printf("second : %d\n", str->second);
	//si largeur et non precision
	tmp = 0;
	tmp2 = 0;
	if (str->first && !str->second && !str->fzero)
	{	
		tmp = str->first - ft_strlen(str->sentence);
		if (str->fless)
		{	
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
			ft_putstr_fd(str->sentence, 1, str);
		}
	}
	// si precision mais pas largeur
	if (!str->first && (str->fdot || str->fzero) && str->second)
	{
		tmp = str->second - ft_strlen(str->sentence);
		if (tmp > 0 && !str->fless)
		{	
			while (tmp--)
				ft_putchar_fd('0', 1, str);
		}
		ft_putstr_fd(str->sentence, 1, str);
	}
	else if (str->first && str->fzero && !str->second)
	{
		tmp = str->first - ft_strlen(str->sentence);
		if (tmp > 0 && !str->fless)
		{	
			while (tmp--)
				ft_putchar_fd('0', 1, str);
		}
		ft_putstr_fd(str->sentence, 1, str);
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
				while (tmp2--)
					ft_putchar_fd('0', 1, str);
			}
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
				while (tmp2--)
					ft_putchar_fd('0', 1, str);
			}
			ft_putstr_fd(str->sentence, 1, str);
		}
	}
	if (!str->first && !str->second)
		ft_putstr_fd(str->sentence, 1, str);
}

void	conv_for_u(t_type *str)
{
	if (str->second < 0)
			str->second = 0;
	str->u_d = va_arg(str->ap, unsigned int);
	str->sentence = ft_uitoa_base(str->u_d, 10, "0123456789");
	if (str->fdot && !str->second && str->remember) 
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
	print_for_u(str);
}
