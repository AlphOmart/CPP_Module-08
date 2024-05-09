#---COMMON_VAR-----------------------------------
NAME		=	Easyfind
CXX			=	c++
FLAGS		=	-std=c++98 -Wall -Werror -Wextra -g3
#---PROJECT+VAR----------------------------------
SRC			=	main.cpp

OBJS_DIR	=	.OBJS/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRC:.cpp=.o))
HEADER		=	easyfind.hpp \
				easyfind.tpp
DEP			=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))
#---RULES----------------------------------------

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
				@echo "\033[0;33m\nCOMPILING $(NAME)...\n"
				@$(CXX) $(FLAGS) $(OBJS) -o $@
				@echo "\033[1;32m./$(NAME) created\n\033[0m"

-include $(DEP)

$(OBJS_DIR)%.o:	%.cpp | dir
				@$(CXX) $(FLAGS) -c $< -o $@

dir:			$(OBJS_DIR)

$(OBJS_DIR):
				@mkdir -p $(OBJS_DIR)
				@mkdir -p $(OBJS_DIR)src

clean:
				@echo "\033[0;31mDeleting $(NAME) object...\n"
				@$(RM) -rf $(OBJS_DIR)
				@echo "\033[1;32mDone\n"

fclean:			clean
				@echo "\033[0;31mDeleting $(NAME) executable..."
				@rm -rf $(NAME)
				@echo "\033[1;32mDone\n"

re:				fclean
				$(MAKE) all

.PHONY:			all clean fclean re
