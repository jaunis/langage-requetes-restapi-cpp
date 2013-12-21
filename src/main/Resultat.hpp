#include <list>
#include <map>
#include <string>

#ifndef RESULTAT_HPP_
#define RESULTAT_HPP_

using namespace std;

class AnalyseurJson;

class Resultat {
private:
    list<map<string, string> >& tuples;
    friend AnalyseurJson;
public:
    Resultat();
    virtual ~Resultat();
    list<map<string, string> >& accTuples();
};

#endif
