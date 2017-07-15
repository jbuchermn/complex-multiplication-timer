CXX     = g++-6
CFLAGS  = -Ofast -I./lib
LDFLAGS = -lstdc++

default: main

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

main: main.o
	$(CXX) -o main main.o $(LDFLAGS)

clean:
	@rm -f *.o
	@rm -f main
