SRCDIR	=	sources

SRC	= 	$(SRCDIR)/main.cpp \
		$(SRCDIR)/Evolver.cpp \
		$(SRCDIR)/Polygon.cpp \
		$(SRCDIR)/DNA.cpp

OBJ	= 	$(SRC:.cpp=.o)

NAME	= 	volution

INC	=	-I./includes

FLAGS	=	-Wall -Wextra 

BOOST	=	 -lboost_program_options

CXXFLAGS+=	$(INC) $(FLAGS)

all	: 	$(NAME)

$(NAME)	: 	$(OBJ)
		g++ -o $(NAME) $(OBJ)  $(BOOST)

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all
