NAME        := fixed
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -Wpedantic -std=c++17 #-g
OBJDIR      := obj

SRCS        := main.cpp Fixed.cpp
OBJS        := $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
