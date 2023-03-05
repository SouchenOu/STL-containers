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


NAME = containers

FILES = map/main_map.cpp Red_black_Tree/main_tree.cpp set/main_set.cpp stack/main_stack.cpp vector/main_vector.cpp main_subject.cpp main2.cpp

INC = map/map.hpp Red_black_Tree/Red_black_tree.hpp Red_black_Tree/Node.hpp set/set.hpp stack/stack.hpp vector/iterators_traits.hpp vector/vector_iterator.hpp vector/vector_reverse_iterator.hpp vector/vector.hpp enable_if.hpp equal.hpp is_integral.hpp pair.hpp

FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(FILES) $(INC)
	c++ $(FLAGS) $(FILES) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
