#include <string>
#include "Resultat.hpp"
#include <json/json.h>
#include <exception>

#ifndef ANALYSEURJSON_HPP_
#define ANALYSEURJSON_HPP_

using namespace std;

class JsonInvalide: public exception {
private:
    string message;
public:
    JsonInvalide(string);
    virtual ~JsonInvalide() throw ();
    virtual const char * what() const throw ();
};

class AnalyseurJson {
private:
    map<string, string> extraireTuple(json_object* element);
public:
    AnalyseurJson();
    virtual ~AnalyseurJson();
    virtual Resultat& extraireResultat(string&);
};

#endif
