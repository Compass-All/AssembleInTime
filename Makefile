CC = gcc
AS = gcc
CPPFLAGS = -g
LKFLAGS = -T layout.lds -L/usr/lib/aarch64-linux-gnu/ -lc

SRC = main.c
SRC += controller.S

# static = yes

# ifdef static
# 	CPPFLAGS += -static -no-pie -nostdlib -lc -l/usr/lib/aarch64-linux-gnu/libc.a
# else
# 	LKFLAGS += --dynamic-linker /usr/lib/aarch64-linux-gnu/libc-2.28.so /usr/lib/aarch64-linux-gnu/libc.a 
# endif

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