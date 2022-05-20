# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboudarg <aboudarg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 13:36:13 by aboudarg          #+#    #+#              #
#    Updated: 2022/05/19 18:51:45 by aboudarg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# _*_ MakeFile _*_
INC= -I include
S = src/
CHK = tobonus
SRCS			=  $(S)philosopher.c $(S)uitls/ft_atoi.c $(S)uitls/fuitls.c $(S)check_num.c \
					$(S)creation_thread.c $(S)routine_job.c $(S)states.c $(S)observation.c \
					$(S)time.c $(S)messages.c

SRCBS			=  $(S)philosopher.c
 
OBJS			= $(SRCS:.c=.o)
OBJBS			= $(SRCBS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror $(INC)  

NAME			= philo
PHILOSOPHER			= philo_bonus

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
	$(CC) $(OBJS) -o $(NAME) 

bonus:			$(CHECKER)

$(PHILOSOPHER):		$(OBJBS)
	$(CC) $(OBJBS) -o $(CHECKER)

clean:
				$(RM) $(OBJS) $(OBJBS)

fclean:			clean
				$(RM) $(NAME) $(CHECKER)

re:				fclean $(NAME)


.PHONY:			all clean fclean re bonus