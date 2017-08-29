##
## Makefile for  in /home/renard_e/2/ProgElem/trade
## 
## Made by Gregoire Renard
## Login   <renard_e@epitech.net>
## 
## Started on  Mon Jan 30 09:51:48 2017 Gregoire Renard
## Last update Fri Mar 24 13:23:07 2017 Gregoire Renard
##

CC	=	gcc -Iinclude/

RM	=	rm -fr

SRCS	=	main.c \
		src/remp_info.c \
		src/printf_error.c \
		src/set_info.c \
		src/set_cpt_flag.c \
		src/remp_flag.c \
		src/list_fct.c \
		src/fill_first.c \
		src/algo.c \
		src/thread_fct.c \
		src/xlock.c \
		src/init_play.c \

OBJS	=	$(SRCS:.c=.o)

NAME	=	philo

CFLAGS	=	-Wall -Wextra -Werror -W -g3

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) -L. -lriceferee -lpthread

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all re clean fclean
