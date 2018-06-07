##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= libasm.so

T_NAME	=	program

DZCOLOR  = \e[0;33m
LSCOLOR  = \e[0;37m
LICOLOR  = \e[0;31m
RSCOLOR  = \e[1;37m

CC	= gcc

RM	= rm -f

# Source File
SRCS	=	./src/memcpy.asm	\
		./src/memmove.asm	\
		./src/memset.asm	\
		./src/rindex.asm	\
		./src/strcasecmp.asm	\
		./src/strchr.asm	\
		./src/strcmp.asm	\
		./src/strcspn.asm	\
		./src/strlen.asm	\
		./src/strncmp.asm	\
		./src/strpbrk.asm	\
		./src/strstr.asm	\
		./src/read.asm		\
		./src/write.asm	

LDFLAGS += -shared

# Name with .o
OBJS = $(SRCS:.asm=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "$(DZCOLOR)# Generation of .o files correcly done$(LSCOLOR)"
	@echo -e "$(LICOLOR)# Generation of Library$(LSCOLOR)"
	ld -v $(OBJS) $(LDFLAGS) -o $@
	@echo -e "$(DZCOLOR)# Compilation Succesful.$(LSCOLOR)"

%.o : %.asm
	nasm -felf64 $< -o $@

	@echo -e "$(DZCOLOR)# NASM Done$(RSCOLOR)"

exec :
		rm -rf $(T_NAME)
		@echo -e "$(LICOLOR)# Compilation for Testing Program$(RSCOLOR)"
		$(CC) main.c $(OBJS) -o $(T_NAME) -g -O0
		@echo -e "$(DZCOLOR)# Compilation Successful$(LSCOLOR)"

clean:
	$(RM) $(OBJS)
	@echo -e "$(LICOLOR)# Deleting .o files$(LSCOLOR)"

fclean: clean
	$(RM) $(NAME)
	@echo -e "$(LICOLOR)# Deleting Library$(LSCOLOR)"

re: fclean all

test: re exec

.PHONY: all clean fclean re
