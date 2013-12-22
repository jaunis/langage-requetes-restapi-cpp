#include "Executeur.hpp"

Executeur::Executeur(UtilitaireHttp& utilitaire, AnalyseurJson& analyseur): utilitaire(utilitaire), analyseur(analyseur)
{}

Executeur::Executeur()  {

}

Executeur::~Executeur()
{
    // TODO Auto-generated destructor stub
}

Resultat& Executeur::executer(Requete& requete) {
    string& json = utilitaire.executerGet(requete.accCible());
    return analyseur.extraireResultat(json);
}
