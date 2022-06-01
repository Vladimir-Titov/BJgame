NAME = blackjack

SRC		=	main.cpp	Game.cpp	DrawImage.cpp\
			Card.cpp	Deck.cpp	Player.cpp\

SRCS	=	$(addprefix src/, $(SRC))

OBJ		=	$(SRCS:.cpp=.o)

IFLAGC  = -I../SFML/include

FLAGS	=	-L../SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

.PHONY	:	all clean fclean re debug

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	g++ -o $(NAME) $(FLAGS) $(OBJ)

%.o		:	%.cpp
	g++ -c $< -o $@ $(IFLAGC) 

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all