#include <string>
#include <list>

#ifndef ANALYSEURSYNTAXIQUE_H_
#define ANALYSEURSYNTAXIQUE_H_

class Requete;

using namespace std;

namespace analyseurs {
class ErreurSyntaxe : public exception {
public:
    ErreurSyntaxe(string message, string complement="");
    virtual ~ErreurSyntaxe() throw ();
    virtual const char * what() const throw ();

private:
    string message;
};

class AnalyseurSyntaxique {
private:
    enum Etat {DEBUT, PROJECTION_DEBUT, PROJECTION_VIRGULE, FROM, CIBLE, FIN};
    Etat etat;
    //list<string>::iterator it;

public:
    AnalyseurSyntaxique();
    virtual ~AnalyseurSyntaxique();
    Requete& creerRequete(list<string>) throw (ErreurSyntaxe);
};

}

#endif /* ANALYSEURSYNTAXIQUE_H_ */
