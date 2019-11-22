/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:13:50 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/22 09:40:57 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

void	ft_putchar_fd(char c, int fd, t_type *str)
{
	if (fd >= 0)
		write(fd, &c, 1);
	str->len++;
}
