# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgadinga <sgadinga@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 23:33:41 by sgadinga          #+#    #+#              #
#    Updated: 2025/06/15 23:17:42 by sgadinga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes
ARCHIVE = ar rcs

SRC_DIR = src
OBJ_DIR = obj

EXTRAS = ft_strtol.c
SRCS = $(addprefix $(SRC_DIR)/, \
		 ft_isalpha.c ft_isdigit.c ft_islower.c ft_isupper.c ft_isspace.c \
		 ft_isprint.c ft_isascii.c ft_itoa.c ft_atoi.c ft_bzero.c ft_calloc.c \
		 ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		 ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_split.c ft_strchr.c \
		 ft_strdup.c ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c \
		 ft_strjoin.c ft_strmapi.c ft_striteri.c ft_lstnew.c ft_lstadd_front.c \
		 ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		 ft_lstiter.c ft_lstmap.c $(EXTRAS))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@	

$(NAME): $(OBJS)
	$(ARCHIVE) $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
