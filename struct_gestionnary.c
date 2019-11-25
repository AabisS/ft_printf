/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_gestionnary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:15:28 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/25 12:23:40 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	print(char c, int tmp, t_type *str)
{
	if (tmp > 0)
		while (tmp--)
			ft_putchar_fd(c, 1, str);
}

void	initialize_all(t_type *str)
{
	str->fdot = 0;
	str->fless = 0;
	str->fzero = 0;
	str->fstar = 1;
	str->first = 0;
	str->second = 0;
	str->remember = 0;
	str->d_i = 0;
	str->car = 0;
	str->p = NULL;
	str->u_d = 0;
}

void	print_for_p5(t_type *str, int tmp, int tmp2, char *sentence)
{
	if ((size_t)str->second > ft_strlen(sentence))
		tmp = str->first - str->second - 2;
	else
		tmp = (size_t)str->first - ft_strlen(sentence) - 2;
	tmp2 = (size_t)str->second - ft_strlen(sentence);
	print_for_p6(str, tmp, tmp2, sentence);
}

void	print_for_p6(t_type *str, int tmp, int tmp2, char *sentence)
{
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
		ft_putstr_fd(sentence, 1, str);
		print(' ', tmp, str);
	}
	else if (!str->fless)
		print_for_p7(str, tmp, tmp2, sentence);
}

void	print_for_p7(t_type *str, int tmp, int tmp2, char *sentence)
{
	print(' ', tmp2, str);
	if (tmp2 > 0)
	{
		ft_putstr_fd("0x", 1, str);
		print('0', tmp, str);
		tmp2 = -1;
	}
	else if (tmp2 != -1)
		ft_putstr_fd("0x", 1, str);
	ft_putstr_fd(sentence, 1, str);
}
