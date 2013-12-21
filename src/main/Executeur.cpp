#include "Executeur.hpp"

Executeur::Executeur(UtilitaireHttp& utilitaire, AnalyseurJson& analyseur): utilitaire(utilitaire), analyseur(analyseur)
{}

Executeur::~Executeur()
{
    // TODO Auto-generated destructor stub
}

Resultat& Executeur::executer(Requete& requete) {
    string& json = utilitaire.executerGet("/1.1/devices");
    return analyseur.extraireResultat(json);
}
