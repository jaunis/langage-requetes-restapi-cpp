//#define BOOST_TEST_MODULE TestAnalyseurLexical
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <list>
#include <string>
#include "../main/AnalyseurLexical.hpp"

using namespace std;
using namespace analyseurs;

BOOST_AUTO_TEST_CASE(divisier_en_lexemes) {
    AnalyseurLexical analyseur;
    list<string>& resultat = analyseur.diviser_en_lexemes("select * from devices");
    string attendu[] = {"select", "*", "from", "devices"};
    list<string> attenduList(attendu, attendu + sizeof attendu/sizeof attendu[0]);
    BOOST_CHECK_EQUAL_COLLECTIONS(resultat.begin(), resultat.end(), attenduList.begin(), attenduList.end());
}

BOOST_AUTO_TEST_CASE(divisier_en_lexemes_virgules) {
    AnalyseurLexical analyseur;
    list<string>& resultat = analyseur.diviser_en_lexemes("select mac, ip,id from devices");
    string attendu[] = {"select", "mac", ",", "ip", ",", "id", "from", "devices"};
    list<string> attenduList(attendu, attendu + sizeof attendu/sizeof attendu[0]);
    BOOST_CHECK_EQUAL_COLLECTIONS(resultat.begin(), resultat.end(), attenduList.begin(), attenduList.end());
}
