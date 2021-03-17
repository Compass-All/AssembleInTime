CC = gcc
AS = gcc
CPPFLAGS = -g

SRC = main.c
SRC += controller.S


TMP_OBJ = $(SRC:.c=.o)
OBJ = $(TMP_OBJ:.S=.o)
EXEC = main

all: $(EXEC) asm

$(EXEC): $(OBJ) layout.lds
	ld -T layout.lds --dynamic-linker /usr/lib/aarch64-linux-gnu/libc-2.28.so /usr/lib/aarch64-linux-gnu/libc.a  -o $@ $(OBJ) 
	# ld -o $@ $(OBJ) -T layout.lds

run: all
	./main

asm: $(EXEC)
	objdump -d $(EXEC) > $(EXEC).asm

clean:
	rm -rf $(OBJ) $(EXEC)
	rm -rf *.asm