CC      = gcc
CFLAGS  = -Ofast
LDFLAGS =

default: main

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

main: main.o
	$(CC) -o main main.o $(LDFLAGS)

clean:
	@rm -f *.o
	@rm -f main
