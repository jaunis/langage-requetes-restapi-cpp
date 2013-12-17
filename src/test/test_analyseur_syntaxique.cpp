#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <string>
#include "../main/AnalyseurSyntaxique.hpp"
#include "../main/Requete.hpp"

using namespace std;
using namespace analyseurs;

BOOST_AUTO_TEST_CASE(test_creer_requete) {
    AnalyseurSyntaxique analyseur;
    string lexemes[] = {"select", "*", "from", "devices"};
    list<string> listeLexemes(lexemes, lexemes + sizeof lexemes/sizeof lexemes[0]);
    Requete requete = analyseur.creerRequete(listeLexemes);
    BOOST_CHECK_EQUAL("devices", requete.accCible());
    string projection[] = {"*"};
    BOOST_CHECK_EQUAL_COLLECTIONS(projection, projection + sizeof projection/sizeof projection[0], requete.accProjection().begin(), requete.accProjection().end());
}
