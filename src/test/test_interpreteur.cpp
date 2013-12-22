#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "turtle/mock.hpp"
#include "../main/Interpreteur.hpp"
#include <string>

using namespace std;

MOCK_BASE_CLASS( MockAnalyseurLexical, analyseurs::AnalyseurLexical ) {
    MOCK_METHOD(diviser_en_lexemes, 1)
};

MOCK_BASE_CLASS( MockAnalyseurSytaxique, analyseurs::AnalyseurSyntaxique ) {
    MOCK_METHOD(creerRequete, 1)
};

MOCK_BASE_CLASS( MockExecuteur, Executeur) {
    MOCK_METHOD(executer, 1)
};

MOCK_BASE_CLASS( MockAfficheur, Afficheur) {
    MOCK_METHOD(afficher, 1)
};

BOOST_AUTO_TEST_CASE(test_traiter_requete) {
    MockAnalyseurLexical anLex;
    MockAnalyseurSytaxique anSynt;
    MockExecuteur exec;
    MockAfficheur afficheur;
    Interpreteur interpreteur(anLex, anSynt, exec, afficheur);
    string requete = "select * from devices";
    list<string> lexemes;
    Requete requeteObj;
    Resultat resultat;
    MOCK_EXPECT(anLex.diviser_en_lexemes).with(requete).once().returns(lexemes);
    MOCK_EXPECT(anSynt.creerRequete).once().returns(requeteObj);
    MOCK_EXPECT(exec.executer).once().returns(resultat);
    MOCK_EXPECT(afficheur.afficher).once();
    interpreteur.traiterRequete(requete);
}
