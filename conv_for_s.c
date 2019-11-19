#include "ft_printf.h"
#include "./libft/libft.h"

static void	print(char c, int tmp, t_type *str)
{
	if (tmp > 0)
		while (tmp--)
			ft_putchar_fd(c, 1, str);
}

static void	first(t_type *str)
{
	int tmp;

	tmp = str->first - ft_strlen(str->sentence);
	if (str->fless)
	{
		ft_putstr_fd(str->sentence, 1, str);
		print(' ', tmp, str);
	}
	else
	{
		print(' ', tmp, str);
		ft_putstr_fd(str->sentence, 1, str);
	}
}

static void	second(t_type *str)
{
	int tmp;

	tmp = str->second;
	if (tmp >= 0)
			str->sentence = ft_substr(str->sentence, 0, tmp);
	ft_putstr_fd(str->sentence, 1, str);
}

static void    print_for_s(t_type *str)
{
	int tmp;
    if (!str->first && str->fdot && str->second)
		second(str);
	else if (str->first && !str->second && !str->fdot)
		first(str);
	else if (str->first && str->fdot && (str->second || str->remember))
	{
		tmp = str->first - str->second;
		if (str->fless)
		{	
			second(str);
			print(' ', tmp, str);
		}
		else
		{
			print(' ', tmp, str);
			second(str);
		}
	}
	else if (!str->first && !str->fdot && !str->second)
		ft_putstr_fd(str->sentence, 1, str);
}

static void	parse_flag(t_type *str)
{
	if (str->fdot && str->second == 0)
	{
		str->remember = 1;
		str->second = 0;
	}
	if (str->second > ft_strlen(str->sentence) && str->fdot && str->first)
		str->remember = 1;
	if (str->fdot && str->second < 0)
		str->second = ft_strlen(str->sentence);
	if (str->second && str->second > ft_strlen(str->sentence))
		str->second = ft_strlen(str->sentence);
	if (str->first < 0)
	{
		str->fless = 1;
		str->first = -str->first;
	}
	//printf("first : %d\n", str->first);
	//printf("sec : %d\n", str->second);
	//printf("rem : %d\n", str->remember);
	//printf("zero : %d\n", str->fzero);
	//printf("dot : %d\n", str->fdot);
	//printf("less : %d\n", str->fless);
}

void    conv_for_s(t_type *str)
{
    if (!(str->sentence = va_arg(str->ap, char *)))
	{	
		free(str->sentence);
        str->sentence = ft_strdup("(null)");
	}
	parse_flag(str);
    print_for_s(str);
}
