/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:10:41 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/11 16:28:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	find_flags(char *format, t_type *str)
{
	int i;

	i = 0;
	if (format[i] == '-')
	{
		str->fless = 1;
		while (format[i] == '-')
		{
			if (format[i + 1] == '.')
				str->fless = 0;
			i++;
		}
	}
	if (format[i] == '0')
	{
		str->fzero = 1;
		while (format[i] == '0')
			i++;
	}
	if (format[i] >= '1' && format[i] <= '9')
	{
		str->first = ft_atoi(&format[i]);
		i += ft_strlen(ft_itoa(str->first));
	}
	else if (format[i] == '*')
	{
		str->first = va_arg(str->ap, int);
		if (str->first < 0)
		{
			str->fless = 1;
			str->first *= -1;
		}
		i++;
	}
	if (format[i] == '.')
	{
		str->fdot = 1;
		i++;
	}
	if (format[i] >= '1' && format[i] <= '9')
	{
		str->second = ft_atoi(&format[i]);
		i += ft_strlen(ft_itoa(str->second));
	}
	else if (format[i] == '*')
	{
		str->second = va_arg(str->ap, int);
		i++;
	}
	return (i);
}
