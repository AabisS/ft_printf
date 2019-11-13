/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:05:25 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/13 13:18:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_printf(char *format, ...)
{
	t_type	str;
	int		i;

	i = -1;
	va_start(str.ap, format);
	str.len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			initialize_all(&str);
			i += find_flags(&format[i], &str);
			find_conversion(&str, &format[i]);
			i++;
		}
		ft_putchar_fd(format[i], 1, &str);
	}
	va_end(str.ap);
	return (str.len);
}
