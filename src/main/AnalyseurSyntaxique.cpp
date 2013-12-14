/*
 * AnalyseurSyntaxique.cpp
 *
 *  Created on: 14 déc. 2013
 *      Author: jean
 */

#include "AnalyseurSyntaxique.hpp"

namespace analyseurs {

AnalyseurSyntaxique::AnalyseurSyntaxique()
{
    // TODO Auto-generated constructor stub

}

AnalyseurSyntaxique::~AnalyseurSyntaxique()
{
    // TODO Auto-generated destructor stub
}

Requete& AnalyseurSyntaxique::creerRequete(list<string> lexemes) {
    return *new Requete();
}

}
