#include "Resultat.hpp"
#include <set>

#ifndef AFFICHEUR_HPP_
#define AFFICHEUR_HPP_

class Afficheur {
private:
    void afficherLigne(map<string, string>& ligne, list<string>& projection);
    list<string>& trouverColonnesAAfficher(list<map<string, string> >& tuples, list<string>& projection);
    list<string>& trouverToutesLesColonnes(list<map<string, string> >& tuples);

public:
    Afficheur();
    virtual ~Afficheur();
    virtual void afficher(Resultat& resultat, list<string>& projection);
};

#endif
