/*
 * AnalyseurLexical.cpp
 *
 *  Created on: 11 déc. 2013
 *      Author: jean
 */

#include "AnalyseurLexical.hpp"
#include <sstream>

namespace analyseurs {

AnalyseurLexical::AnalyseurLexical()
{
    // TODO Auto-generated constructor stub

}

AnalyseurLexical::~AnalyseurLexical()
{
    // TODO Auto-generated destructor stub
}

list<string>& AnalyseurLexical::diviser_en_lexemes(string requete) {
    list<string>& resultat = *new list<string>();
    istringstream iss(requete);
    string lexeme;
    while (getline(iss, lexeme, ' ')) {
        string sousLexeme = lexeme;
        string::size_type position = string::npos;
        while((position = sousLexeme.find(",")) != string::npos) {
            resultat.push_back(sousLexeme.substr(0, position));
            resultat.push_back(",");
            if(position + 1 < sousLexeme.size())
                sousLexeme = sousLexeme.substr(position + 1);
            else
                sousLexeme = "";
        }
        if(!sousLexeme.empty())
            resultat.push_back(sousLexeme);
    }
    return resultat;
}
}
