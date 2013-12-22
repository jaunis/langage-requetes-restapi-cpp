#include <string>
#include <list>

#ifndef ANALYSEURSYNTAXIQUE_H_
#define ANALYSEURSYNTAXIQUE_H_

class Requete;

using namespace std;

namespace analyseurs {
class ErreurSyntaxe : public exception {
private:
    string message;

public:
    ErreurSyntaxe(string message, string complement="");
    virtual ~ErreurSyntaxe() throw ();
    virtual const char * what() const throw ();

};

class AnalyseurSyntaxique {
private:
    enum Etat {DEBUT, PROJECTION_DEBUT, PROJECTION_VIRGULE, FROM, CIBLE, FIN};
    Etat etat;
    //list<string>::iterator it;

public:
    AnalyseurSyntaxique();
    virtual ~AnalyseurSyntaxique();
    virtual Requete& creerRequete(list<string>);
};

}

#endif /* ANALYSEURSYNTAXIQUE_H_ */
