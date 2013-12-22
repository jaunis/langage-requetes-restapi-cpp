#include "Resultat.hpp"

#ifndef AFFICHEUR_HPP_
#define AFFICHEUR_HPP_

class Afficheur {
private:
    void afficherLigne(map<string, string>& ligne, list<string>& projection);

public:
    Afficheur();
    virtual ~Afficheur();
    virtual void afficher(Resultat& resultat, list<string>& projection);
};

#endif
