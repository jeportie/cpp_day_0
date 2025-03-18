# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 11:16:03 by jeportie          #+#    #+#              #
#    Updated: 2025/03/17 11:16:09 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OUTDIR = bin
SRCDIR = src
OBJDIR = obj

#### BEGIN AUTO GENERATED FILES ###
# List of source files:
SRC = \
  src/megaphone.cpp \
  src/utils.cpp 
### END AUTO GENERATED FILES ###

OBJS = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS = $(OBJ:.o=.d)

all: $(OUTDIR)/$(NAME)

# Linking rule
$(OUTDIR)/$(NAME): $(OBJS) | $(OUTDIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

# Directories creation
$(OUTDIR):
	mkdir -p $(OUTDIR)

# Rules
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(OUTDIR)

re: fclean all

build_and_run: all
	./$(OUTDIR)/$(NAME)

run:
	./$(OUTDIR)/$(NAME)

.PHONY: all clean fclean re build_and_run run
