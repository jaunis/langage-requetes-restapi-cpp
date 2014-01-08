#include "Interpreteur.hpp"

int main(int argc, char** argv) {
    AnalyseurJson anJson;
    UtilitaireHttp utilHttp("localhost", "50050");
    Executeur executeur(utilHttp, anJson);
    analyseurs::AnalyseurLexical anLex;
    analyseurs::AnalyseurSyntaxique anSynt;
    Afficheur afficheur;
    Interpreteur interpreteur(anLex, anSynt, executeur, afficheur);
    if(argc != 2) {
        printf("Argument manquant.");
        return -1;
    }
    string requete(argv[1]);
    interpreteur.traiterRequete(requete);
    return 0;
}
