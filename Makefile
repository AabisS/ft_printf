SRCS = ft_printf.c \
       struct_gestionnary.c \
       find_flags.c \
       find_conversion.c \
       conv_for_d.c \
       conv_for_s.c \
       conv_for_x.c \
       conv_for_xx.c \

OBJS = ${SRCS:%.c=%.o}
NAME = libftprintf.a
HEADER = ft_printf.h 
HEADER2 = ./libft/libft.h 
CC = gcc
CFLAGS = -c -I.${HEADER} 

all : ${NAME}	

clean : 
		rm -f ${OBJS}

fclean : clean
		 rm -f ${NAME}

$(NAME) : ${OBJS} ${HEADER} $(HEADER2)
		  ar rc ${NAME} ${OBJS}
		  ranlib ${NAME}

re : fclean all

.PHONY : all clean re fclean
