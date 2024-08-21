PROG = dist/main
CC = g++
CPPFLAGS = -O0 -g -std=c++11 -Wall -pedantic
OBJS = dist/main.o dist/Autocomplete.o dist/Term.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

dist/main.o: src/main.cpp
	mkdir -p dist
	$(CC) $(CPPFLAGS) -c src/main.cpp -o dist/main.o

dist/Autocomplete.o: src/classes/autocomplete/Autocomplete.cpp src/classes/autocomplete/Autocomplete.h
	mkdir -p dist
	$(CC) $(CPPFLAGS) -c src/classes/autocomplete/Autocomplete.cpp -o dist/Autocomplete.o

dist/Term.o: src/classes/term/Term.cpp src/classes/term/Term.h
	mkdir -p dist
	$(CC) $(CPPFLAGS) -c src/classes/term/Term.cpp -o dist/Term.o


clean:
	rm -f $(PROG) $(OBJS)
