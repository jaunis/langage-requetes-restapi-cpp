#include <string>
#include "Resultat.hpp"
#include <json/json.h>

#ifndef ANALYSEURJSON_HPP_
#define ANALYSEURJSON_HPP_

using namespace std;

class AnalyseurJson {
private:
    map<string, string> extraireTuple(json_object* element);
public:
    AnalyseurJson();
    virtual ~AnalyseurJson();
    virtual Resultat& extraireResultat(string&);
};

#endif
