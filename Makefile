PROG = bin/autocompletar
CC = g++
CPPFLAGS = -O0 -g -std=c++11 -Wall -pedantic
OBJS = bin/main.o bin/Autocomplete.o bin/Term.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

bin/main.o: src/main.cpp
	mkdir -p bin
	$(CC) $(CPPFLAGS) -c src/main.cpp -o bin/main.o

bin/Autocomplete.o: src/classes/autocomplete/Autocomplete.cpp src/classes/autocomplete/Autocomplete.h
	mkdir -p bin
	$(CC) $(CPPFLAGS) -c src/classes/autocomplete/Autocomplete.cpp -o bin/Autocomplete.o

bin/Term.o: src/classes/term/Term.cpp src/classes/term/Term.h
	mkdir -p bin
	$(CC) $(CPPFLAGS) -c src/classes/term/Term.cpp -o bin/Term.o


clean:
	rm -f $(PROG) $(OBJS)
