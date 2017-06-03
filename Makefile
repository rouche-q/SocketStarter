CC		=	gcc

RM		=	rm -rf

SDIR	=	sources/

IDIR	=	includes/

CFLAGS	+=	-W -Wall -Wextra -Werror -ansi -pedantic -I$(IDIR) -g3

NAME	= 	server

SRCS	=	$(SDIR)main.c 			\
			$(SDIR)socket.c 		\
			$(SDIR)init.c 			\
			$(SDIR)dowhatyouwant.c	\

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
