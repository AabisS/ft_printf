/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:15:48 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/13 13:22:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd, t_type *str)
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
		ft_putchar_fd('\n', fd, str);
	}
}
