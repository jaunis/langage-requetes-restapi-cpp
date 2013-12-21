#include <string>
#include "Resultat.hpp"

#ifndef ANALYSEURJSON_HPP_
#define ANALYSEURJSON_HPP_

using namespace std;

class AnalyseurJson {
public:
    AnalyseurJson();
    virtual ~AnalyseurJson();
    virtual Resultat& extraireResultat(string);
};

#endif
