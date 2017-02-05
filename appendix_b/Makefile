CC = gcc
CC_FLAGS =
SRC = $(wildcard *.c)
PROGS = $(basename $(SRC))

.PHONY: all clean

all: $(PROGS)

%: %.c
	$(CC) -o $@ $(CC_FLAGS) $<

clean:
	rm -f *.o *.a $(PROGS)
