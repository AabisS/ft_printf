/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:15:12 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/13 13:19:30 by marvin           ###   ########.fr       */
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
		while (s[i])
		{
			ft_putchar_fd(s[i], fd, str);
			i++;
		}
	}
}
