/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:07:57 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/25 12:40:11 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static void	second(t_type *str, char *sentence)
{
	int tmp;

	if (str->fzero && str->fdot)
		tmp = (size_t)str->second - ft_strlen(str->sentence);
	else
		tmp = (size_t)str->second - ft_strlen(sentence);
	if (str->d_i < 0)
	{
		ft_putchar_fd('-', 1, str);
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

	tmp = (size_t)str->first - ft_strlen(str->sentence);
	if (str->fless)
	{
		str->d_i ? ft_putnbr_fd(str->d_i, 1, str) :
		ft_putstr_fd(sentence, 1, str);
		!str->fzero ? print(' ', tmp, str) : print('0', tmp, str);
	}
	else
	{
		if (str->d_i < 0 && str->fzero)
			ft_putchar_fd('-', 1, str);
		!str->fzero ? print(' ', tmp, str) : print('0', tmp, str);
		if (str->d_i < 0 && str->fzero)
			str->d_i ? ft_putstr_fd(sentence, 1, str) :
			ft_putstr_fd(sentence, 1, str);
		else
			str->d_i ? ft_putnbr_fd(str->d_i, 1, str) :
			ft_putstr_fd(sentence, 1, str);
	}
}

void		print_for_d_i(t_type *str, char *sentence)
{
	if (!str->first && str->fdot && str->second)
		second(str, sentence);
	else if (str->first && !str->second && !str->fdot)
		first(str, sentence);
	else if (str->first && str->fdot && (str->second || str->remember))
		print_for_d_i2(str, sentence);
	else if (!str->first && !str->second && !str->fdot)
		ft_putnbr_fd(str->d_i, 1, str);
}

void		print_for_d_i2(t_type *str, char *sentence)
{
	int tmp;

	if (str->d_i < 0 && str->second)
		tmp = str->first - str->second - 1;
	else if (str->d_i >= 0 && str->second)
		tmp = str->first - str->second;
	else
		tmp = (size_t)str->first - ft_strlen(str->sentence);
	if (str->fless)
	{
		second(str, sentence);
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
		second(str, sentence);
	}
}

void		conv_for_d(t_type *str)
{	
	char *sentence;
	char *cpy;

	sentence = NULL;
	str->d_i = va_arg(str->ap, int);
	sentence = ft_itoa(str->d_i);
	cpy = sentence;
	str->sentence = ft_strdup(sentence);
	sentence = parse_flag_d(str, sentence);
	print_for_d_i(str, sentence);
	free(str->sentence);
	free(cpy);
}
