/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:26:57 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/21 13:28:11 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static void	first(t_type *str)
{
	int tmp;

	tmp = (size_t)str->first - ft_strlen(str->sentence);
	if (str->fless)
	{
		ft_putstr_fd(str->sentence, 1, str);
		print(' ', tmp, str);
	}
	else
	{
		print(' ', tmp, str);
		ft_putstr_fd(str->sentence, 1, str);
	}
}

static void	second(t_type *str)
{
	int tmp;

	tmp = str->second;
	if (tmp >= 0)
		str->sentence = ft_substr(str->sentence, 0, tmp);
	ft_putstr_fd(str->sentence, 1, str);
}

static void	print_for_s(t_type *str)
{
	int tmp;

	if (!str->first && str->fdot && str->second)
		second(str);
	else if (str->first && !str->second && !str->fdot)
		first(str);
	else if (str->first && str->fdot && (str->second || str->remember))
	{
		tmp = str->first - str->second;
		if (str->fless)
		{
			second(str);
			print(' ', tmp, str);
		}
		else
		{
			print(' ', tmp, str);
			second(str);
		}
	}
	else if (!str->first && !str->fdot && !str->second)
		ft_putstr_fd(str->sentence, 1, str);
}

void		conv_for_s(t_type *str)
{
	if (!(str->sentence = va_arg(str->ap, char *)))
	{
		free(str->sentence);
		str->sentence = ft_strdup("(null)");
	}
	parse_flag_s(str);
	print_for_s(str);
}
