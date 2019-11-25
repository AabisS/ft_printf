/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:26:57 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/25 12:40:09 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static void	first(t_type *str, char *sentence)
{
	int tmp;

	tmp = (size_t)str->first - ft_strlen(sentence);
	if (str->fless)
	{
		ft_putstr_fd(sentence, 1, str);
		print(' ', tmp, str);
	}
	else
	{
		print(' ', tmp, str);
		ft_putstr_fd(sentence, 1, str);
	}
}

static void	second(t_type *str, char *sentence)
{
	int tmp;
	char *res;
	
	tmp = str->second;
	if (tmp >= 0)
		res = ft_substr(sentence, 0, tmp);
	(tmp >= 0) ? ft_putstr_fd(res, 1, str) : ft_putstr_fd(sentence, 1, str);
	if (tmp >= 0)
		free(res);
}

static void	print_for_s(t_type *str, char *sentence)
{
	int tmp;

	if (!str->first && str->fdot && str->second)
		second(str, sentence);
	else if (str->first && !str->second && !str->fdot)
		first(str, sentence);
	else if (str->first && str->fdot && (str->second || str->remember))
	{
		tmp = str->first - str->second;
		if (str->fless)
		{
			second(str, sentence);
			print(' ', tmp, str);
		}
		else
		{
			print(' ', tmp, str);
			second(str, sentence);
		}
	}
	else if (!str->first && !str->fdot && !str->second)
		ft_putstr_fd(sentence, 1, str);
}

void		conv_for_s(t_type *str)
{
	char *sentence;
	int bool_free;

	bool_free = 0;
	if (!(sentence = va_arg(str->ap, char *)))
	{
		sentence = ft_strdup("(null)");
		bool_free = 1;
	}
	parse_flag_s(str, sentence);
	print_for_s(str, sentence);
	if (bool_free)
		free(sentence);
}
