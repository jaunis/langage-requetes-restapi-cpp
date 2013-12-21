#include "AnalyseurJson.hpp"

AnalyseurJson::AnalyseurJson()
{
    // TODO Auto-generated constructor stub

}

AnalyseurJson::~AnalyseurJson()
{
    // TODO Auto-generated destructor stub
}

Resultat& AnalyseurJson::extraireResultat(string) {
    return *new Resultat();
}
