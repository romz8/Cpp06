# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 19:29:31 by rjobert           #+#    #+#              #
#    Updated: 2024/02/15 16:17:31 by romainjober      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = Serializer
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -I ./ 
HEADER = Serializer.hpp Data.h
SRC = Serializer.cpp main.cpp
OBJS = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)
RM = rm -rf

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile $(HEADER )
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re