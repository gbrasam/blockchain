/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 09:28:41   			       #+#    #+#             */
/*   Updated: 2024/12/09 14:55:05         			   ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

NAME            = scontract

SRC_FILES		= set_score \
				  get_score \
				  rank_users \
				  sort_users \
				  utils \
				  main \

SRC_DIR			= srcs/
OBJ_DIR			= objs/
INCLUDE_DIR		= include/

CC              = gcc
CFLAGS          = -Wall -Werror -Wextra -I$(INCLUDE_DIR) -g3 -fsanitize=thread
RM              = rm -f

SRC				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all:            $(NAME)

$(NAME):		$(OBJ)
				@$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o: 	$(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -o $@ -c $^

clean:
				@$(RM) $(OBJ)
				@$(RM) -r $(OBJ_DIR)

fclean:         clean
				@$(RM) $(NAME)

re:             fclean all		

.PHONY:         all clean fclean re

