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
OUTDIR = bin
OBJDIR = obj

### BEGIN AUTO GENERATED FILES ###
# List of source files:
SRC = \
  megaphone.cpp
### END AUTO GENERATED FILES ###
OBJS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUTDIR)/$(NAME): $(OBJS)
	@mkdir -p $(OUTDIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(OUTDIR)/$(NAME)
	
all: $(NAME)

clean:
	rm -f $(OBJDIR)

fclean: clean
	rm -f $(OUTDIR)

re: fclean all

build_and_run: all
	./$(OUTDIR)/$(NAME)

run:
	./$(OUTDIR)/$(NAME)

.PHONY: all clean fclean re
