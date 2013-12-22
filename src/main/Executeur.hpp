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
protected:
    Executeur();
public:
    Executeur(UtilitaireHttp&, AnalyseurJson&);
    virtual ~Executeur();
    virtual Resultat& executer(Requete&);
};

#endif
