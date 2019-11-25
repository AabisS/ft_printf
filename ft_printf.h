/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarckma <fmarckma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:02:35 by fmarckma          #+#    #+#             */
/*   Updated: 2019/11/25 12:22:15 by fmarckma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

typedef struct		s_type
{
	va_list			ap;
	int				fdot;
	int				fless;
	int				fzero;
	int				fstar;
	int				first;
	int				second;
	int				remember;
	int				d_i;
	unsigned int	u_d;
	char			*sentence;
	char			*result;
	char			car;
	void			*p;
	int				len;
}					t_type;

int					ft_printf(const char *format, ...);
void				initialize_all(t_type *str);
int					find_flags(char *format, t_type *str);
int					find_flags_follow(char *format, int i, t_type *str);
void				find_conversion(t_type *str, char *format);
void				conv_for_d(t_type *str);
void				conv_for_s(t_type *str);
void				conv_for_c(t_type *str);
void				conv_for_p(t_type *str);
void				conv_for_x(t_type *str);
void				conv_for_xx(t_type *str);
void				conv_for_pourcentage(t_type *str);
void				conv_for_u(t_type *str);
void				print(char c, int tmp, t_type *str);
void				parse_flag_s(t_type *str, char *sentence);
char				*parse_flag_x(t_type *str, char *sentence);
void				parse_flag_x2(t_type *str, char *sentence);
char				*parse_flag_d(t_type *str, char *sentence);
void				parse_flag_d2(t_type *str, char *sentence);
void				print_for_d_i(t_type *str, char *sentence);
void				print_for_d_i2(t_type *str, char *sentence);
void				print_for_p(t_type *str, char *sentence);
void				print_for_p2(t_type *str, int tmp, int tmp2,
char *sentence);
void				print_for_p3(t_type *str, int tmp, int tmp2,
char *sentence);
void				print_for_p4(t_type *str, int tmp, int tmp2,
char *sentence);
void				print_for_p5(t_type *str, int tmp, int tmp2,
char *sentence);
void				print_for_p6(t_type *str, int tmp, int tmp2,
char *sentence);
void				print_for_p7(t_type *str, int tmp, int tmp2,
char *sentence);

#endif
