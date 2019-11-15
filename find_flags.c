/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:10:41 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/15 14:24:05 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	is_charset(char *charset, char c)
{
	int i;

	i = 0;
	while (charset[i])
		if (charset[i++] == c)
			return (1);
	return (0);
}

int	find_flags(char *format, t_type *str)
{
	int i;
	char *charset;

	i = 0;
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
			str->fless = 1;
		if (format[i] == '0')
			str->fzero = 1;
		i++;
	}
	if (ft_isdigit(format[i]))
	{
		str->first = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	else if (format[i] == '*')
	{
		str->first = va_arg(str->ap, int);
		i++;
	}
	if (format[i] == '.')
	{
		str->fdot = 1;
		i++;
	}
	if (ft_isdigit(format[i]))
	{
		str->second = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	else if (format[i] == '*')
	{
		str->second = va_arg(str->ap, int);
		i++;
	}
	return (i);
}
