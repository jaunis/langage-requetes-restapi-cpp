#ifndef EXECUTEUR_HPP_
#define EXECUTEUR_HPP_

#include "Requete.hpp"
#include "Resultat.hpp"
#include "UtilitaireHttp.hpp"
#include "AnalyseurJson.hpp"

class Executeur {
private:
    AnalyseurJson& analyseur;
    UtilitaireHttp& utilitaire;
public:
    Executeur(UtilitaireHttp&, AnalyseurJson&);
    virtual ~Executeur();
    Resultat& executer(Requete&);
};

#endif
