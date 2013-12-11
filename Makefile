DEBUG=yes
ifeq ($(DEBUG), yes)
    CFLAGS=-lcurl -ljson -g 
else
    CFLAGS=-lcurl -ljson
endif
TESTFLAGS=

MAIN = bin/interpreteur.o

OBJECTS = bin/main/AnalyseurLexical.o

TEST_OBJECTS = bin/test/test_analyseur_lexical.o

all: $(OBJECTS) $(MAIN)
	rm -f bin/tests.o; g++ -o interpreteur $(OBJECTS) $(MAIN) $(CFLAGS)

test: $(OBJECTS) $(TEST_OBJECTS)
	rm -f $(MAIN); g++ -o tests $(OBJECTS) $(TEST_OBJECTS) $(CFLAGS) $(TESTFLAGS)

clean:
	rm -f bin/**/*.o bin/*.o tests interpreteur

bin/%.o: src/%.cpp
	g++ -c $< -o $@ $(CFLAGS) $(TESTFLAGS)

