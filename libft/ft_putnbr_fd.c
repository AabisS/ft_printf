/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:16:07 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/13 13:22:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

void	ft_putnbr_fd(int n, int fd, t_type *str)
{
	if (fd >= 0)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd('-', fd, str);
			ft_putchar_fd('2', fd, str);
			n = 147483648;
		}
		if (n < 0)
		{
			ft_putchar_fd('-', fd, str);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd, str);
			ft_putnbr_fd(n % 10, fd, str);
		}
		if (n < 10)
		{
			ft_putchar_fd(n + '0', fd, str);
		}
	}
}
