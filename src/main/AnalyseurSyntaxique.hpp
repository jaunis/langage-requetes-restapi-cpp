/*
 * AnalyseurSyntaxique.h
 *
 *  Created on: 14 déc. 2013
 *      Author: jean
 */

#include <string>
#include <list>
#include "Requete.hpp"

#ifndef ANALYSEURSYNTAXIQUE_H_
#define ANALYSEURSYNTAXIQUE_H_

using namespace std;

namespace analyseurs {

class AnalyseurSyntaxique {
public:
    AnalyseurSyntaxique();
    virtual ~AnalyseurSyntaxique();
    Requete& creerRequete(list<string>);
};

}

#endif /* ANALYSEURSYNTAXIQUE_H_ */
