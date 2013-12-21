#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <string>
#include "../main/AnalyseurJson.hpp"

using namespace std;

BOOST_AUTO_TEST_CASE(test_extraire_resultat) {
    AnalyseurJson analyseur;
    string json =
            "{\"items\": [{\"champ1\": \"valeur1\", \"champ2\": 2}, {\"champ1\": \"valeur001\", \"champ3\": 3, \"champ4\": null}]}";
    Resultat& resultat = analyseur.extraireResultat(json);
    list<map<string, string> > tuples = resultat.accTuples();
    int i = 0;
    for (list<map<string, string> >::iterator it = tuples.begin(); it != tuples.end(); it++) {
        if (i == 0) {
            BOOST_CHECK_EQUAL("valeur1", it->find("champ1")->second);
            BOOST_CHECK_EQUAL(string("2"), it->find("champ2")->second);
        } else if (i == 1) {
            BOOST_CHECK_EQUAL(string("valeur001"), it->find("champ1")->second);
            BOOST_CHECK_EQUAL(string("3"), it->find("champ3")->second);
            BOOST_CHECK_EQUAL(string(), it->find("champ4")->second);
        } else {
            BOOST_FAIL("Un élément en trop dans la liste");
        }
        i++;
    }
    BOOST_CHECK(i == 2);
}
