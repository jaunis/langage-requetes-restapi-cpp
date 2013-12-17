/*
 * AnalyseurSyntaxique.cpp
 *
 *  Created on: 14 déc. 2013
 *      Author: jean
 */

#include "AnalyseurSyntaxique.hpp"
#include "Requete.hpp"

namespace analyseurs {

AnalyseurSyntaxique::AnalyseurSyntaxique() {
    etat = DEBUT;
}

AnalyseurSyntaxique::~AnalyseurSyntaxique() {
    // TODO Auto-generated destructor stub
}

Requete& AnalyseurSyntaxique::creerRequete(list<string> lexemes) {
    Requete& requete = *new Requete();
    for (list<string>::iterator it = lexemes.begin(); it != lexemes.end(); it++) {
        if (etat == DEBUT) {
            if (it->compare("select") != 0)
                throw -1;
            etat = PROJECTION;
        } else if (etat == PROJECTION) {
            requete.projection.push_front(*it);
            etat = FROM;
        } else if (etat == FROM) {
            if (it->compare("from") != 0)
                throw -1;
            etat = CIBLE;
        } else if (etat == CIBLE) {
            requete.cible = *it;
            etat = FIN;
        } else if (etat == FIN) {
            throw -1;
        }
    }
    if (etat != FIN)
        throw -1;
    return requete;
}

}
