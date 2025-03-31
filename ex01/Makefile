# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 11:16:03 by jeportie          #+#    #+#              #
#    Updated: 2025/03/19 10:59:11 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myPhoneBook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OUTDIR = bin
SRCDIR = src
OBJDIR = obj
MAIN = main.cpp

#### BEGIN AUTO GENERATED FILES ###
# List of source files:
SRC = \
  src/Contact.class.cpp \
  src/PhoneBook.class.private.cpp \
  src/PhoneBook.class.public.cpp 
### END AUTO GENERATED FILES ###

# Create object for main.cpp
MAIN_OBJ = $(OBJDIR)/main.o

# Pattern rule for src files (for .cpp files)
OBJS = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o) $(MAIN_OBJ)

# Dependency files (if needed)
DEPS = $(OBJ:.o=.d)

all: $(OUTDIR)/$(NAME)

# Linking rule
$(OUTDIR)/$(NAME): $(OBJS) | $(OUTDIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Compile rule for .cpp files in src
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

# Compile rule for main.cpp
$(OBJDIR)/main.o: main.cpp
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
