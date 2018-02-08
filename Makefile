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
SRC		= $(shell ls sources/src | grep -E ".+\.c")
VSRC	= $(shell ls sources/visual | grep -E ".+\.c")
ODIR	:= sources/obj
OBJ		:= $(addprefix $(ODIR)/,$(SRC:%.c=%.o))
VOBJ	:= $(addprefix $(ODIR)/,$(VSRC:%.c=%.o))
INC		= sources/includes
LIB		= sources/libft.a
EX		= lem-in
BONUS	= visualizer


all: $(LIB) $(EX)

$(EX): $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC) -o $(EX) $(OBJ) -L./sources/ -lft

$(ODIR)/%.o:sources/src/%.c | $(ODIR)
	@$(CC) $(CFLAGS) -I $(INC) -I sources/minilibx -o $@ -c $<

$(ODIR):
	@mkdir $(ODIR)

$(LIB):
	@make -C sources/libft/

$(BONUS): $(LIB) $(OBJ) $(VOBJ)
	@make -C sources/minilibx/
	@$(CC) $(CFLAGS) -I $(INC) -I sources/minilibx -o $(BONUS) $(VOBJ) -L sources -lft -L sources/minilibx -lmlx -framework OpenGL -framework AppKit

$(ODIR)/%.o:sources/visual/%.c | $(ODIR)
	@$(CC) $(CFLAGS) -I $(INC) -I sources/minilibx -o $@ -c $<

clean:
	@rm -rf sources/obj
	@make -C sources/libft/ clean
	@make -C sources/minilibx/ clean

fclean: clean
	@rm -f $(EX) $(BONUS)
	@make -C sources/libft/ fclean

re: fclean all

.PHONY: clean fclean all re visual

