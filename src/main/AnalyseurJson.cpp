#include "AnalyseurJson.hpp"
#include <json/json.h>
#include <json/json_tokener.h>

AnalyseurJson::AnalyseurJson()
{
    // TODO Auto-generated constructor stub

}

AnalyseurJson::~AnalyseurJson()
{
    // TODO Auto-generated destructor stub
}

Resultat& AnalyseurJson::extraireResultat(string& json) {
    Resultat& resultat = *new Resultat();
    json_object* jobj = json_tokener_parse(json.c_str());
    json_object* contenu;
    json_object_object_get_ex(jobj, "items", &contenu);
    for (int i = 0; i < json_object_array_length(contenu); i++) {
        json_object* element = json_object_array_get_idx(contenu, i);
        resultat.tuples.push_back(extraireTuple(element));
    }
    return resultat;
}

map<string, string> AnalyseurJson::extraireTuple(json_object* element) {
    map<string, string> tuple;
    json_object_object_foreach(element, key, val) {
        json_type type = json_object_get_type(val);
        if (type == json_type_double || type == json_type_int || type == json_type_string
                || type == json_type_boolean) {
            tuple.insert(make_pair(string(key), string(json_object_get_string(val))));
        } else if (type == json_type_null) {
            tuple.insert(make_pair(string(key), string()));
        }
    }
    return tuple;
}
