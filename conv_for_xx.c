/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:31:02 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/25 13:02:42 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static void	second(t_type *str, char *sentence)
{
	int tmp;

	if (str->fzero && str->fdot)
		tmp = (size_t)str->second - ft_strlen(sentence);
	else
		tmp = (size_t)str->second - ft_strlen(sentence);
	if (str->u_d < 0)
	{
		print('0', tmp, str);
		ft_putstr_fd(sentence, 1, str);
	}
	else
	{
		print('0', tmp, str);
		ft_putstr_fd(sentence, 1, str);
	}
}

static void	first(t_type *str, char *sentence)
{
	int tmp;

	tmp = (size_t)str->first - ft_strlen(sentence);
	if (str->fless)
	{
		ft_putstr_fd(sentence, 1, str);
		!str->fzero ? print(' ', tmp, str) : print('0', tmp, str);
	}
	else
	{
		!str->fzero ? print(' ', tmp, str) : print('0', tmp, str);
		ft_putstr_fd(sentence, 1, str);
	}
}

static void	print_for_xx(t_type *str, char *sentence)
{
	int tmp;

	if (!str->first && str->fdot && str->second)
		second(str, sentence);
	else if (str->first && !str->second && !str->fdot)
		first(str, sentence);
	else if (str->first && str->fdot && (str->second || str->remember))
	{
		if (str->u_d >= 0 && str->second)
			tmp = str->first - str->second;
		else
			tmp = (size_t)str->first - ft_strlen(sentence);
		if (str->fless)
		{
			second(str, sentence);
			str->fzero ? print('0', tmp, str) : print(' ', tmp, str);
		}
		else
		{
			str->fzero ? print('0', tmp, str) : print(' ', tmp, str);
			second(str, sentence);
		}
	}
	else if (!str->first && !str->second && !str->fdot)
		ft_putstr_fd(sentence, 1, str);
}

void		conv_for_xx(t_type *str)
{
	char *sentence;

	str->u_d = va_arg(str->ap, unsigned int);
	if (!(sentence = ft_uitoa_base(str->u_d, 16, "0123456789ABCDEF")))
	{
		str->err = 1;
		return ;
	}
	parse_flag_x(str, sentence);
	print_for_xx(str, sentence);
	free(sentence);
}
