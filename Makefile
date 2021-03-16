CC = gcc
AS = gcc
CPPFLAGS = -g

SRC = main.c
SRC += controller.S


TMP_OBJ = $(SRC:.c=.o)
OBJ = $(TMP_OBJ:.S=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $(OBJ)

run: all
	./main

asm: $(EXEC)
	objdump -d $(EXEC) > $(EXEC).asm

clean:
	rm -rf $(OBJ) $(EXEC)
	rm -rf *.asm