#ifndef EXECUTEUR_HPP_
#define EXECUTEUR_HPP_

#include "Requete.hpp"
#include "Resultat.hpp"

class Executeur {
public:
    Executeur();
    virtual ~Executeur();
    Resultat& executer(Requete&);
};

#endif
