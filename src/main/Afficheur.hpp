#include "Resultat.hpp"

#ifndef AFFICHEUR_HPP_
#define AFFICHEUR_HPP_

class Afficheur {
public:
    Afficheur();
    virtual ~Afficheur();
    virtual void afficher(Resultat&);
};

#endif
