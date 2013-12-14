/*
 * Requete.h
 *
 *  Created on: 14 déc. 2013
 *      Author: jean
 */

#include <string>
#include <list>

#ifndef REQUETE_H_
#define REQUETE_H_

using namespace std;

class Requete {
private:
    string cible;
    list<string>& projection;
public:
    Requete();
    virtual ~Requete();
    string accCible();
    list<string>& accProjection();
};

#endif /* REQUETE_H_ */
