#include <string>
#include <list>

#ifndef ANALYSEURSYNTAXIQUE_H_
#define ANALYSEURSYNTAXIQUE_H_

class Requete;

using namespace std;

namespace analyseurs {

class AnalyseurSyntaxique {
private:
    enum Etat {DEBUT, PROJECTION, FROM, CIBLE, FIN};
    Etat etat;

public:
    AnalyseurSyntaxique();
    virtual ~AnalyseurSyntaxique();
    Requete& creerRequete(list<string>);

};

}

#endif /* ANALYSEURSYNTAXIQUE_H_ */
