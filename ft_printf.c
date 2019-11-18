/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:05:25 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/18 15:23:32 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_printf(const char *format, ...)
{
	t_type	str;
	int		i;

	i = -1;
	va_start(str.ap, format);
	str.len = 0;
	while (format[++i] != 0)
	{
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1, &str);
		else if (format[i] == '%')
		{
			i++;
			initialize_all(&str);
			i += find_flags((char*)&format[i], &str);
			find_conversion(&str, (char*)&format[i]);
		}
	}
	va_end(str.ap);
	return (str.len);
}
