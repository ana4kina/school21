NAME = PhoneBook
SRCS = PhoneBook.cpp Contacts.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}
CPP = c++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}:	${OBJS}
					${CPP} ${CPPFLAGS} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS}
fclean:
			${RM} ${NAME} ${OBJS}

re:			fclean all

.PHONY: all clean fclean re