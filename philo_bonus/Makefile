# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 13:36:13 by aboudarg          #+#    #+#              #
#    Updated: 2022/03/11 15:23:30 by aboudarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _*_ MakeFile _*_
INC= -I include
S = src/
SRCS			=  $(S)philosopher.c $(S)uitls/ft_atoi.c $(S)uitls/fuitls.c $(S)check_num.c \
					 $(S)routine_job.c $(S)states.c $(S)creation_proc.c 
OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror $(INC)  

NAME			= philo_bonus

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
	$(CC) $(OBJS) -o $(NAME) 

clean:
				$(RM) $(OBJS) $(OBJBS)

fclean:			clean
				$(RM) $(NAME) $(CHECKER)

re:				fclean $(NAME)


.PHONY:			all clean fclean re bonus