DEBUG=yes
ifeq ($(DEBUG), yes)
    CFLAGS=-lcurl -ljson -g
else
    CFLAGS=-lcurl -ljson
endif
TESTFLAGS=-I include

MAIN = bin/interpreteur.o

OBJECTS = bin/main/AnalyseurLexical.o
OBJECTS += bin/main/AnalyseurSyntaxique.o
OBJECTS += bin/main/Requete.o
OBJECTS += bin/main/Resultat.o
OBJECTS += bin/main/Executeur.o
OBJECTS += bin/main/UtilitaireHttp.o
OBJECTS += bin/main/AnalyseurJson.o

TEST_OBJECTS = bin/test/test_analyseur_lexical.o
TEST_OBJECTS += bin/test/test_analyseur_syntaxique.o
TEST_OBJECTS += bin/test/test_utilitaire_http.o
TEST_OBJECTS += bin/test/test_executeur.o
TEST_OBJECTS += bin/test/test_analyseur_json.o
TEST_OBJECTS += bin/test/tests.o

all: $(OBJECTS) $(MAIN)
	rm -f bin/tests.o; g++ -o bin/interpreteur $(OBJECTS) $(MAIN) $(CFLAGS)

test: $(OBJECTS) $(TEST_OBJECTS)
	rm -f $(MAIN); g++ -o bin/tests $(OBJECTS) $(TEST_OBJECTS) $(CFLAGS) $(TESTFLAGS)

clean:
	rm -f bin/**/*.o bin/tests bin/interpreteur

bin/main/%.o: src/main/%.cpp src/main/%.hpp
	g++ -c $< -o $@ $(CFLAGS) $(TESTFLAGS)

bin/test/%.o: src/test/%.cpp
	g++ -c $< -o $@ $(CFLAGS) $(TESTFLAGS)