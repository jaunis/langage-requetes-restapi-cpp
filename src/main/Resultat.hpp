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
    Resultat(list<map<string, string> > tuples);
    virtual ~Resultat();
    list<map<string, string> >& accTuples();
    void mutTuples(list<map<string, string> >& tuples);
};

#endif
