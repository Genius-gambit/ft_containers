NAME = ft_containers

SRCS = vector.cpp main.cpp

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror

all: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

clean:
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all
