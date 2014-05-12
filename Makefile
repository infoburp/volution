SRCDIR	=	sources

SRC	= 	$(SRCDIR)/main.cpp \
		$(SRCDIR)/Evolver.cpp \
		$(SRCDIR)/Polygon.cpp \
		$(SRCDIR)/DNA.cpp

OBJ	= 	$(SRC:.cpp=.o)

NAME	= 	volution

INC	=	-I./includes

FLAGS	=	-Wall -Wextra -std=gnu++11

BOOST	=	 -lboost_program_options -lboost_system

CXXFLAGS+=	$(INC) $(FLAGS) -DDEBUG  

all	: 	$(NAME)

$(NAME)	: 	$(OBJ)
		g++ -o $(NAME) $(OBJ)  $(BOOST) -lOpenCL

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all
