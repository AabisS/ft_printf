SRCS = ft_printf.c \
       struct_gestionnary.c \
       find_flags.c \
       find_conversion.c \
       conv_for_d.c \
       conv_for_s.c \
       conv_for_c.c \
       conv_for_x.c \
       conv_for_pourcentage.c \
       conv_for_xx.c \
       conv_for_p.c \
       conv_for_u.c \

OBJS = ${SRCS:%.c=%.o}
NAME = libftprintf.a
HEADER = ft_printf.h 
HEADER2 = ./libft/libft.h 
CC = gcc
CFLAGS = -c -I.${HEADER}
FT		= ./libft/
FT_INC	= ./libft/*.o
FT_LNK	= ./libft/libft.a

all : lib ${NAME} 

clean : 
		rm -f ${OBJS} $(FT_INC)

fclean : clean
		 rm -f ${NAME}

lib :
	      make bonus -C $(FT)

$(NAME) : ${OBJS} ${HEADER2} $(HEADER) $(FT_LNK)
		  ar rc ${NAME} ${OBJS} $(FT_INC)
		  ranlib ${NAME}

re : fclean all

.PHONY : all clean re fclean
