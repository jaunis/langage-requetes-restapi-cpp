#include "Afficheur.hpp"
#include <iostream>
#include <map>

Afficheur::Afficheur()
{
    // TODO Auto-generated constructor stub

}

Afficheur::~Afficheur()
{
    // TODO Auto-generated destructor stub
}

void Afficheur::afficher(Resultat& resultat, list<string>& projection) {
    list<map<string, string> > tuples = resultat.accTuples();
    int i = 0;
    for(list<string>::iterator it = projection.begin(); it != projection.end(); it++) {
        i++;
        cout << *it;
        if(i != projection.size())
            cout << ",";
    }
    cout << endl;
    for(list<map<string, string> >::iterator it=tuples.begin(); it != tuples.end(); it++) {
        afficherLigne(*it, projection);
    }
}

void Afficheur::afficherLigne(map<string, string>& ligne, list<string>& projection) {
    int i = 0;
    for(list<string>::iterator it = projection.begin(); it != projection.end(); it++) {
            i++;
            map<string, string>::iterator paire = ligne.find(*it);
            if(paire != ligne.end())
                cout << paire->second;
            if(i != projection.size())
                cout << ",";
    }
    cout << endl;
}
