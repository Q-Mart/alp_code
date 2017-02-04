OBJECTS = createfile
LIBS =
PROGRAMS = create-file hexdump timestamp lseek-huge

.PHONY: all clean

all: $(OBJECTS) $(LIBS) $(PROGRAMS)

clean:
	rm -f *.o *.a $(PROGRAMS)

create-file:
	gcc -o create-file create-file.c

