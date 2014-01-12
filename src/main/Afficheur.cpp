#include "Afficheur.hpp"
#include <iostream>
#include <map>
#include <algorithm>

Afficheur::Afficheur()
{
    // TODO Auto-generated constructor stub

}

Afficheur::~Afficheur()
{
    // TODO Auto-generated destructor stub
}

void Afficheur::afficher(Resultat& resultat, list<string>& projection) {
    list<map<string, string> >& tuples = resultat.accTuples();
    int i = 0;
    list<string>& colonnes_a_afficher = trouverColonnesAAfficher(tuples, projection);
    for(list<string>::iterator it = colonnes_a_afficher.begin(); it != colonnes_a_afficher.end(); it++) {
        i++;
        cout << *it;
        if(i != colonnes_a_afficher.size())
            cout << ",";
    }
    cout << endl;
    for(list<map<string, string> >::iterator it=tuples.begin(); it != tuples.end(); it++) {
        afficherLigne(*it, colonnes_a_afficher);
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

list<string>& Afficheur::trouverColonnesAAfficher(list<map<string, string> >& tuples, list<string>& projection) {
    list<string>& resultat = *new list<string>();
    for(list<string>::iterator it = projection.begin(); it != projection.end(); it++) {
        if(it->compare("*") != 0)
            resultat.push_back(*it);
        else {
            list<string>& toutes_les_colonnes = trouverToutesLesColonnes(tuples);
            resultat.insert(resultat.end(), toutes_les_colonnes.begin(), toutes_les_colonnes.end());
        }
    }
    return resultat;
}

list<string>& Afficheur::trouverToutesLesColonnes(list<map<string, string> >& tuples) {
    list<string>& resultat = *new list<string>();
    for(list<map<string, string> >::iterator it = tuples.begin(); it != tuples.end(); it++) {
        for(map<string, string>::iterator itCol = it->begin(); itCol != it->end(); itCol++) {
            if(std::find(resultat.begin(), resultat.end(), itCol->first) == resultat.end()) {
                resultat.push_back(itCol->first);
            }
        }
    }
    return resultat;
}
