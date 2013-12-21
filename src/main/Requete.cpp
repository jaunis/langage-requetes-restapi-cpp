/*
 * Requete.cpp
 *
 *  Created on: 14 déc. 2013
 *      Author: jean
 */

#include "Requete.hpp"

Requete::Requete() : projection(*new list<string>)
{
    // TODO Auto-generated constructor stub

}

Requete::~Requete()
{
    // TODO Auto-generated destructor stub
}

string Requete::accCible() {
    return cible;
}

list<string>& Requete::accProjection() {
    return projection;
}

void Requete::mutCible(string cible) {
    this->cible = cible;
}
