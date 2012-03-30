##
## Makefile for testage in /home/el-out_y//test/gdl
## 
## Made by youssef el-outmani
## Login   <el-out_y@epitech.net>
## 
## Started on  Wed May 25 17:17:35 2011 youssef el-outmani
## Last update Sun Jun  5 23:28:15 2011 robin garbo
##

NAME		=	Bomberman

DIR		=	src/

SRC		=	$(DIR)main.cpp		\
			$(DIR)MyGame.cpp	\
			$(DIR)AObject.cpp	\
			$(DIR)Camera.cpp	\
			$(DIR)Wall.cpp		\
			$(DIR)BreakableWall.cpp \
			$(DIR)Floor.cpp		\
			$(DIR)Map.cpp		\
			$(DIR)Personnage.cpp	\
			$(DIR)Bomb.cpp		\
			$(DIR)Bonus.cpp		\
			$(DIR)Flame.cpp

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-W -Wall -Werror

RM		=	rm -f

CC		=	g++

INCLUDE		+=	-I/home/robin/Documents/lib/gamedevlab/include -I./include/

LDFLAGS		=	-L/home/robin/Documents/lib/gamedevlab/lib -Wl,--rpath=/home/robin/Documents/lib/gamedevlab/lib -lgdl_gl -lGL -lGLU



$(NAME)		: $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all		: $(NAME)

clean		:
		$(RM) $(OBJ)

fclean		: clean
		$(RM) $(NAME)

re		: fclean all

.cpp.o		:
		$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@
