/*
 * AnalyseurSyntaxique.cpp
 *
 *  Created on: 14 déc. 2013
 *      Author: jean
 */

#include "AnalyseurSyntaxique.hpp"
#include "Requete.hpp"
#include <sstream>

namespace analyseurs {

AnalyseurSyntaxique::AnalyseurSyntaxique() {
    etat = DEBUT;
}

AnalyseurSyntaxique::~AnalyseurSyntaxique() {
    // TODO Auto-generated destructor stub
}

Requete& AnalyseurSyntaxique::creerRequete(list<string> lexemes) throw(ErreurSyntaxe) {
    Requete& requete = *new Requete();
    for (list<string>::iterator it = lexemes.begin(); it != lexemes.end(); it++) {
        if (etat == DEBUT) {
            if (it->compare("select") != 0)
                throw ErreurSyntaxe("attendu : select, reçu : ", *it);
            etat = PROJECTION_DEBUT;
        } else if (etat == PROJECTION_DEBUT) {
            requete.projection.push_back(*it);
            etat = PROJECTION_VIRGULE;
        } else if(etat == PROJECTION_VIRGULE) {
            if(it->compare(",") == 0)
                etat = PROJECTION_DEBUT;
            else
                etat = FROM;
        }

        if (etat == FROM) {
            if (it->compare("from") != 0)
                throw ErreurSyntaxe("attendu : from, reçu : ", *it);
            etat = CIBLE;
        } else if (etat == CIBLE) {
            requete.cible = *it;
            etat = FIN;
        } else if (etat == FIN) {
            throw ErreurSyntaxe("fin de la requête attendue, mais reste : ", *it);
        }
    }
    if (etat != FIN)
        throw ErreurSyntaxe(string("fin prématurée de la requête"));
    return requete;
}

ErreurSyntaxe::ErreurSyntaxe(string message, string complement) {
    ostringstream oss;
    oss << "Erreur de syntaxe : " << message << complement;
    this->message = oss.str();
}

ErreurSyntaxe::~ErreurSyntaxe() throw (){}

const char* ErreurSyntaxe::what() const throw () {
    return message.c_str();
}
}
