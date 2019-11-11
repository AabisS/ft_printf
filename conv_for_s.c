#include "ft_printf.h"
#include "./libft/libft.h"

void    print_for_s(t_type *str)
{
    int tmp;
    int i;

    i = 0;
   	if (str->first && !str->second && !str->fzero)
	{	
		tmp = str->first - ft_strlen(str->sentence);
		if (str->fless)
		{
			ft_putstr_fd(str->sentence, 1);
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
		}
		//pour largeur positif
		if (!str->fless)
		{
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
			ft_putstr_fd(str->sentence, 1);
		}
	}
    if (!str->first && str->fdot && str->second)
	{
		tmp = str->second;
		if (tmp > 0 && !str->fless)
		{	
			while (tmp--)
				ft_putchar_fd(str->sentence[i++], 1);
		}
	}
    if (str->first && str->second && str->fdot)
	{
		if (str->fless)
		{
            tmp = str->second;
            if (tmp > 0)
                while (tmp--)
                    ft_putchar_fd(str->sentence[i++], 1);
            tmp = str->first - str->second;
			if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
		}
		else if (!str->fless)
		{
            tmp = str->first - str->second;
        	if (tmp > 0)
				while (tmp--)
					ft_putchar_fd(' ', 1);
            tmp = str->second;
            if (tmp > 0)
                while (tmp--)
			        ft_putchar_fd(str->sentence[i++], 1);
		}
	}
    else if (!str->fzero && !str->fstar && !str->fless && !str->fdot)
        ft_putstr_fd(str->sentence, 1);
}

void    conv_for_s(t_type *str)
{
    if (!(str->sentence = va_arg(str->ap, char *)))
        str->sentence = ft_strdup("(null");
    if (str->second < 0 || (str->second > ft_strlen(str->sentence)))
        str->second = ft_strlen(str->sentence);
    print_for_s(str);
}