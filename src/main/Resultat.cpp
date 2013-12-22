#include "Resultat.hpp"

using namespace std;

Resultat::Resultat(): tuples(*new list<map<string, string> >()){}

Resultat::Resultat(list<map<string, string> > tuples) : tuples(tuples) {}

Resultat::~Resultat()
{
    // TODO Auto-generated destructor stub
}

list<map<string, string> >& Resultat::accTuples() {
    return tuples;
}

void Resultat::mutTuples(list<map<string, string> >& tuples) {
    this->tuples.clear();
    this->tuples.merge(tuples);
}
