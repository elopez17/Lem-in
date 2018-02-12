NO_COLOR= \x1b[0m
B_GRY	= \x1b[30;01m
B_RED	= \x1b[31;01m
B_GRN	= \x1b[32;01m
B_YEL	= \x1b[33;01m
B_BLU	= \x1b[34;01m
B_PURP	= \x1b[35;01m
B_TURQ	= \x1b[36;01m
B_WHT	= \x1b[37;01m
GRY		= \x1b[30m
RED		= \x1b[31m
GRN		= \x1b[32m
YEL		= \x1b[33m
BLU		= \x1b[34m
PURP	= \x1b[35m
TURQ	= \x1b[36m
WHT		= \x1b[37m
CC		= gcc
CFLAGS	= -Wall -Wextra
SRC		= error.c getdata.c getlinks.c list.c main.c move_ants.c steps.c
ODIR	:= sources/obj
OBJ		:= $(addprefix $(ODIR)/,$(SRC:%.c=%.o))
INC		= sources/includes
LIB		= sources/libft.a
EX		= lem-in

all: $(LIB) $(EX)

$(EX): $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC) -o $(EX) $(OBJ) -L./sources/ -lft
	@printf "\n"

$(ODIR)/%.o:sources/src/%.c | $(ODIR)
	@printf "$(GRN)▋"
	@$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

$(ODIR):
	@mkdir $(ODIR)

$(LIB):
	@make -C sources/libft/

clean:
	@rm -rf sources/obj
	@make -C sources/libft/ clean

fclean: clean
	@rm -f $(EX)
	@make -C sources/libft/ fclean

re: fclean all

.PHONY: clean fclean all re

