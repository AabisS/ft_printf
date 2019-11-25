/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:15:12 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/25 11:55:39 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

void	ft_putstr_fd(char *s, int fd, t_type *str)
{
	int i;

	i = 0;
	if (s && fd >= 0)
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd, str);
			i++;
		}
	}
}
