CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= \
	main.cpp \
	node/node.cpp \
	Hash/funcao_hash/funcao_hash.cpp \
	Hash/encadeamento_explicito_hash/encadeamento_explicito.cpp \
	Hash/encadeamento_explicito_hash/encadeamento_explicito_saida.cpp \
	Hash/duplo_hash/duplo_hash.cpp \
	Hash/duplo_hash/duplo_hash_saida.cpp \
	Hash/sondagem_linear_hash/sondagem_linear.cpp \
	Hash/sondagem_linear_hash/sondagem_linear_saida.cpp \
	Hash/perfeito_hash/hash_perfeito.cpp \
	Hash/perfeito_hash/hash_perfeito_saida.cpp
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
	./criadorDeEntradas 101 100

run:
	./$(EXECUTABLE) <$(ENTRY_FILE) >saida.txt
run-especial:
	./criadorDeEntradas 101 100
	./$(EXECUTABLE) <$(ENTRY_FILE) >saida10.txt