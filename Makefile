# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 17:45:54 by souchen           #+#    #+#              #
#    Updated: 2023/02/18 17:45:55 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ./containers

FILES = map/main.cpp Red_black_Tree/main.cpp set/main.cpp stack/main.cpp vector/main.cpp

INC = map/map.hpp Red_black_Tree/Red_black_tree.hpp Red_black_Tree/Red_black_tree_iter.hpp set/set.hpp stack/stack.hpp vector/iterators_traits.hpp vector/vector_iterator.hpp vector/vector_reverse_iterator.hpp vector/vector.hpp enable_if.hpp equal.hpp is_integral.hpp pair.hpp


FLAGS -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(FILES) $(INC)
	(rm -rf $(NAME) && mkdir $(NAME))
	c++ $(FLAGS) $(FILES)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
