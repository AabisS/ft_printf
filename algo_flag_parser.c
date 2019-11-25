/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_flag_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:43:18 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/25 11:41:52 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	parse_flag_s(t_type *str, char *sentence)
{
	if (str->fdot && str->second == 0)
	{
		str->remember = 1;
		str->second = 0;
	}
	if ((size_t)str->second > ft_strlen(sentence) &&
	str->fdot && str->first)
		str->remember = 1;
	if (str->fdot && str->second < 0)
		str->second = (int)ft_strlen(sentence);
	if (str->second && (size_t)str->second > ft_strlen(sentence))
		str->second = (int)ft_strlen(sentence);
	if (str->first < 0)
	{
		str->fless = 1;
		str->first = -str->first;
	}
}

char	*parse_flag_x(t_type *str, char *sentence)
{
	if (str->fless && !str->first)
		str->fless = 0;
	if (!str->second && !str->u_d && str->fdot)
	{
		sentence[0] = ' ';
		sentence[1] = 0;
	}
	if (!str->second && !str->u_d && !str->fdot)
	{
		sentence[0] = '0';
		sentence[1] = 0;
	}
	if (str->first && str->fzero && str->fdot && str->second >= 0)
		str->fzero = 0;
	if (str->fzero && str->first > 0 && !str->second && !str->fdot)
	{
		str->second = str->first;
		str->first = 0;
		str->fdot = 1;
	}
	if (str->fzero && str->first < 0 && !str->second && !str->fdot)
		str->fzero = 0;
	if (str->second && (size_t)str->second < ft_strlen(sentence))
		str->second = (int)ft_strlen(sentence);
	parse_flag_x2(str, sentence);
	return (sentence);
}

void	parse_flag_x2(t_type *str, char *sentence)
{
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
	if (!str->first && !str->second && str->fdot && str->u_d)
		str->fdot = 0;
	if (!str->first && !str->u_d && str->fdot && !str->second)
		str->fzero = 1;
	if (str->fdot && str->fstar < 0 && !str->u_d)
	{
		sentence[0] = '0';
		sentence[1] = 0;
		str->fdot = 0;
	}
	if (str->fless && str->fzero)
		str->fzero = 0;
}

char	*parse_flag_d(t_type *str, char *sentence)
{
	if (str->fzero && str->fdot && str->fstar >= 0)
		str->fzero = 0;
	if (str->fzero && str->fdot && str->second && !str->first)
		str->fzero = 1;
	if (str->fless && !str->first)
		str->fless = 0;
	if (str->fzero && str->first > 0 && !str->second && !str->fdot)
	{
		str->second = str->first;
		str->first = 0;
		str->fdot = 1;
	}
	if (str->fdot && !str->second && !str->d_i)
	{
		sentence[0] = ' ';
		sentence[1] = 0;
	}	
	if (sentence[0] == '-')
		sentence = &sentence[1];
	if (str->second && (size_t)str->second < ft_strlen(sentence))
		str->second = (int)ft_strlen(sentence);
	if (str->second <= 0)
	{
		str->remember = 1;
		str->second = 0;
	}
	parse_flag_d2(str, sentence);
	return (sentence);
}

void	parse_flag_d2(t_type *str, char *sentence)
{
	if (str->first < 0)
	{
		str->first = -str->first;
		str->fless = 1;
	}
	if (!str->first && !str->second && str->fdot && str->d_i)
		str->fdot = 0;
	if (str->fdot && str->fstar < 0 && !str->d_i)
	{
		sentence[0] = '0';
		sentence[1] = 0;
		str->fdot = 0;
	}
	if (str->first && str->fdot &&
	(size_t)str->second < ft_strlen(sentence))
	{
		str->fdot = 0;
		str->second = 0;
	}
	if (str->fless && str->fzero)
		str->fzero = 0;
}
