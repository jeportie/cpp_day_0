# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 14:35:27 by jeportie          #+#    #+#              #
#    Updated: 2025/03/11 14:35:28 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = megaphone
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

### BEGIN AUTO GENERATED FILES ###
# List of source files:
SRC = \
  megaphone.cpp
### END AUTO GENERATED FILES ###
OBJS = $(SRC:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

all: $(NAME)
