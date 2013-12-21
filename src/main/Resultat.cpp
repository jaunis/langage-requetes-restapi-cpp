#include "Resultat.hpp"

using namespace std;

Resultat::Resultat(): tuples(*new list<map<string, string> >()){
    // TODO Auto-generated constructor stub

}

Resultat::~Resultat()
{
    // TODO Auto-generated destructor stub
}

list<map<string, string> >& Resultat::accTuples() {
    return tuples;
}
