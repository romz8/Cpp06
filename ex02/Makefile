# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 12:29:16 by romainjober       #+#    #+#              #
#    Updated: 2024/02/16 12:31:45 by romainjober      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = Identify
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -I ./ 
HEADER = Base.hpp A.hpp B.hpp C.hpp
SRC = Base.cpp main.cpp
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