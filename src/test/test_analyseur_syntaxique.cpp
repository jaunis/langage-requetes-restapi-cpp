#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <string>
#include "../main/AnalyseurSyntaxique.hpp"
#include "../main/Requete.hpp"

using namespace std;
using namespace analyseurs;

BOOST_AUTO_TEST_CASE(test_creer_requete) {
    AnalyseurSyntaxique analyseur;
    string lexemes[] = {"select", "mac", ",", "ip", ",", "id", "from", "devices"};
    list<string> listeLexemes(lexemes, lexemes + sizeof lexemes/sizeof lexemes[0]);
    Requete requete = analyseur.creerRequete(listeLexemes);
    BOOST_CHECK_EQUAL("devices", requete.accCible());
    string projection[] = {"mac", "ip", "id"};
    BOOST_CHECK_EQUAL_COLLECTIONS(projection, projection + sizeof projection/sizeof projection[0], requete.accProjection().begin(), requete.accProjection().end());
}

BOOST_AUTO_TEST_CASE(test_creer_requete_mauvaise_projection) {
    AnalyseurSyntaxique analyseur;
    string lexemes[] = {"select", "mac", "ip", ",", "id", "from", "devices"};
    list<string> listeLexemes(lexemes, lexemes + sizeof lexemes/sizeof lexemes[0]);
    BOOST_CHECK_THROW(analyseur.creerRequete(listeLexemes), ErreurSyntaxe);
}

BOOST_AUTO_TEST_CASE(test_creer_requete_mauvais_mot_clef) {
    AnalyseurSyntaxique analyseur;
    string lexemes[] = {"selct", "mac", ",", "ip", ",", "id", "from", "devices"};
    list<string> listeLexemes(lexemes, lexemes + sizeof lexemes/sizeof lexemes[0]);
    BOOST_CHECK_THROW(analyseur.creerRequete(listeLexemes), ErreurSyntaxe);

    string lexemes2[] = {"select", "mac", ",", "ip", ",", "id", "rfom", "devices"};
    list<string> listeLexemes2(lexemes, lexemes + sizeof lexemes/sizeof lexemes[0]);
    BOOST_CHECK_THROW(analyseur.creerRequete(listeLexemes2), ErreurSyntaxe);
}

BOOST_AUTO_TEST_CASE(test_creer_requete_cible_manquante) {
    AnalyseurSyntaxique analyseur;
    string lexemes[] = {"selct", "mac", ",", "ip", ",", "id", "from"};
    list<string> listeLexemes(lexemes, lexemes + sizeof lexemes/sizeof lexemes[0]);
    BOOST_CHECK_THROW(analyseur.creerRequete(listeLexemes), ErreurSyntaxe);
}
