CC = gcc
AS = gcc
CPPFLAGS = -g
LKFLAGS = -T layout.lds -L/usr/lib/aarch64-linux-gnu/ -lc

SRC = main.c
SRC += utils.c
SRC += controller.S

# These are the automatic generated variables
TMP_OBJ = $(SRC:.c=.o)
OBJ = $(TMP_OBJ:.S=.o)
EXEC = target

all: $(EXEC) asm

# Linking Process
$(EXEC): $(OBJ) layout.lds
	ld -o $@ $(OBJ) $(LKFLAGS)

run: all
	./$(EXEC)

asm: $(EXEC)
	objdump -D $(EXEC) > $(EXEC).asm

clean:
	rm -rf $(OBJ) $(EXEC)
	rm -rf *.asm