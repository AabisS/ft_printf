/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_for_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:07:57 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/18 15:53:10 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static void	print(char c, int tmp, t_type *str)
{
	if (tmp > 0)
		while (tmp--)
			ft_putchar_fd(c, 1, str);
}

static void	second(t_type *str)
{
	int tmp;

	if (str->fzero && str->fdot)
		tmp = str->second - ft_strlen(ft_itoa(str->d_i));
	else
		tmp = str->second - ft_strlen(str->sentence);
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

	tmp = str->first - ft_strlen(ft_itoa(str->d_i));
	if (str->fless)
	{
		ft_putnbr_fd(str->d_i, 1, str);
		print(' ', tmp, str);
	}
	else
	{
		print(' ', tmp, str);
		ft_putnbr_fd(str->d_i, 1, str);	
	}
}

static void	print_for_d_i(t_type *str)
{
	int tmp;

	if (!str->first && str->fdot && str->second)
		second(str);
	else if (str->first && !str->second && !str->fdot)
		first(str);
	else if (str->first && str->fdot && (str->second || str->remember))
	{
		if (str->d_i < 0 && str->second)
			tmp = str->first - str->second - 1;
		else if (str->d_i >= 0 && str->second)
			tmp = str->first - str->second;
		else
			tmp = str->first - ft_strlen(ft_itoa(str->d_i));
		if (str->fless)
		{
			second(str);
			str->fzero ? print('0', tmp, str) : print(' ', tmp, str);
		}
		else
		{
			str->fzero ? print('0', tmp, str) : print(' ', tmp, str);
			second(str);
		}
	}
	else if (!str->first && !str->second && !str->fdot)
		ft_putnbr_fd(str->d_i, 1, str);
}

static void	parse_flag(t_type *str)
{
	if (str->fzero && str->fdot && str->second)
		str->fzero = 0;
	if (str->fzero && str->fdot && str->second && !str->first)
		str->fzero = 1;
	if (str->fless && !str->first)
		str->fless = 0;
	if (str->fzero && str->first && !str->second && !str->fdot)
	{
		str->second = str->first;
		str->first = 0;
		str->fdot = 1;
	}
	if (!str->second && !str->d_i)
		str->sentence = ft_strdup(" ");
	if (str->sentence[0] == '-')
		str->sentence = &str->sentence[1];
	if (str->second && str->second < ft_strlen(str->sentence))
		str->second = ft_strlen(str->sentence);
	if (str->second <= 0)
	{
		str->remember = 1;
		str->second = 0;
	}
	if (str->first < 0)
	{
		str->first = -str->first;
		str->fless = 1;
	}
	if (!str->first && !str->second && str->fdot && str->d_i)
		str->fdot = 0;
	//printf("first : %d\n", str->first);
	//printf("sec : %d\n", str->second);
	//printf("rem : %d\n", str->remember);
}

void	conv_for_d(t_type *str)
{
	str->d_i = va_arg(str->ap, int);
	str->sentence = ft_itoa(str->d_i);
	parse_flag(str);
	print_for_d_i(str);
}
