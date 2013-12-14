/*
 * AnalyseurLexical.hpp
 *
 *  Created on: 11 déc. 2013
 *      Author: jean
 */

#include <string>
#include <list>

#ifndef ANALYSEURLEXICAL_HPP_
#define ANALYSEURLEXICAL_HPP_

using namespace std;

namespace analyseurs {

class AnalyseurLexical {
public:
    AnalyseurLexical();
    virtual ~AnalyseurLexical();
    list<string>& diviser_en_lexemes(string);
};

}

#endif /* ANALYSEURLEXICAL_HPP_ */
