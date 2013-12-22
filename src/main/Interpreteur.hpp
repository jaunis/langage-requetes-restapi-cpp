#include <string>
#include "AnalyseurLexical.hpp"
#include "AnalyseurSyntaxique.hpp"
#include "Executeur.hpp"
#include "Afficheur.hpp"

#ifndef INTERPRETEUR_HPP_
#define INTERPRETEUR_HPP_

using namespace std;

class Interpreteur {
private:
    analyseurs::AnalyseurLexical& analyseurLex;
    analyseurs::AnalyseurSyntaxique& analyseurSynt;
    Executeur& executeur;
    Afficheur& afficheur;

public:
    Interpreteur(analyseurs::AnalyseurLexical&, analyseurs::AnalyseurSyntaxique&, Executeur&, Afficheur&);
    virtual ~Interpreteur();
    void traiterRequete(string);
};

#endif
