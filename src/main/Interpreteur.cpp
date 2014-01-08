#include "Interpreteur.hpp"
#include <list>
#include <string>

using namespace std;

Interpreteur::Interpreteur(analyseurs::AnalyseurLexical& analyseurLex, analyseurs::AnalyseurSyntaxique& analyseurSynt,
                           Executeur& executeur, Afficheur& afficheur):
                           analyseurLex(analyseurLex), analyseurSynt(analyseurSynt), executeur(executeur), afficheur(afficheur)
{
    // TODO Auto-generated constructor stub

}

Interpreteur::~Interpreteur()
{
    // TODO Auto-generated destructor stub
}

void Interpreteur::traiterRequete(string requete) {
    list<string>& lexemes = analyseurLex.diviser_en_lexemes(requete);
    Requete& requeteObj = analyseurSynt.creerRequete(lexemes);
    Resultat& resultat = executeur.executer(requeteObj);
    afficheur.afficher(resultat, requeteObj.accProjection());
}
