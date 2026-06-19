# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maalwis <maalwis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 16:42:45 by maalwis           #+#    #+#              #
#    Updated: 2025/04/17 13:43:30 by maalwis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror -I Includes/

LIBFT_SRCS = \
				Sources/Libft/ft_isalpha.c \
				Sources/Libft/ft_isdigit.c \
				Sources/Libft/ft_isalnum.c \
				Sources/Libft/ft_isascii.c \
				Sources/Libft/ft_isprint.c \
				Sources/Libft/ft_strlen.c \
				Sources/Libft/ft_memset.c \
				Sources/Libft/ft_bzero.c \
				Sources/Libft/ft_memcpy.c \
				Sources/Libft/ft_memmove.c \
				Sources/Libft/ft_strlcpy.c \
				Sources/Libft/ft_strlcat.c \
				Sources/Libft/ft_toupper.c \
				Sources/Libft/ft_tolower.c \
				Sources/Libft/ft_strchr.c \
				Sources/Libft/ft_strrchr.c \
				Sources/Libft/ft_strncmp.c \
				Sources/Libft/ft_memchr.c \
				Sources/Libft/ft_memcmp.c \
				Sources/Libft/ft_strnstr.c \
				Sources/Libft/ft_atoi.c \
				Sources/Libft/ft_strdup.c \
				Sources/Libft/ft_calloc.c \
				Sources/Libft/ft_substr.c \
				Sources/Libft/ft_striteri.c \
				Sources/Libft/ft_putchar_fd.c \
				Sources/Libft/ft_putstr_fd.c \
				Sources/Libft/ft_putendl_fd.c \
				Sources/Libft/ft_putnbr_fd.c \
				Sources/Libft/ft_strjoin.c \
				Sources/Libft/ft_strtrim.c \
				Sources/Libft/ft_itoa.c \
				Sources/Libft/ft_strmapi.c \
				Sources/Libft/ft_split.c \
				Sources/Libft/ft_lstnew.c \
				Sources/Libft/ft_lstadd_front.c \
				Sources/Libft/ft_lstsize.c \
				Sources/Libft/ft_lstlast.c \
				Sources/Libft/ft_lstadd_back.c \
				Sources/Libft/ft_lstdelone.c \
				Sources/Libft/ft_lstclear.c \
				Sources/Libft/ft_lstiter.c \
				Sources/Libft/ft_lstmap.c \

FT_PRINTF_SRCS = \
				Sources/Ft_printf/ft_printf.c \
				Sources/Ft_printf/ft_printf_format.c \
				Sources/Ft_printf/ft_printf_utils.c \

GNL_SRCS = \
				Sources/GNL/get_next_line_bonus.c \
				Sources/GNL/get_next_line_utils_bonus.c \
				# Sources/GNL/get_next_line.c \
				Sources/GNL/get_next_line_utils.c \

SRCS = $(LIBFT_SRCS) $(FT_PRINTF_SRCS) $(GNL_SRCS)

OBJ = $(SRCS:.c=.o)

BONUSOBJ = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUSOBJ)
	ar -rcs $(NAME) $(OBJ) $(BONUSOBJ)

clean:
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME) a.out

re:	fclean all

.PHONY: all clean fclean re bonus
