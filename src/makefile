CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Node/node.cpp Hash/hashEncadeamentoExplicito.cpp Hash/hashDouble.cpp Hash/hashLinearProbing.cpp Hash/hashPerfect.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
ENTRY_GENERATOR_SOURCES=criadorDeEntradas.cpp
ENTRY_GENERATOR_OBJECTS=$(ENTRY_GENERATOR_SOURCES:.cpp=.o)
ENTRY_FILE=entrada.txt
EXECUTABLE=program

all: criadorDeEntradas $(SOURCES) $(EXECUTABLE)

criadorDeEntradas: $(ENTRY_GENERATOR_SOURCES)
	$(CC) $(LDFLAGS) $(ENTRY_GENERATOR_SOURCES) -o criadorDeEntradas

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) criadorDeEntradas

run-valgrind: $(ENTRY_FILE) $(EXECUTABLE)
	valgrind --leak-check=full ./$(EXECUTABLE) <$(ENTRY_FILE) >saida.txt

create-input:
	./criadorDeEntradas

run:
	./$(EXECUTABLE) <$(ENTRY_FILE) >saida.txt