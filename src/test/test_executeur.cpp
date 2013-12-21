#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "turtle/mock.hpp"
#include "../main/UtilitaireHttp.hpp"
#include "../main/AnalyseurJson.hpp"
#include "../main/Executeur.hpp"
#include <string>

using namespace std;

MOCK_BASE_CLASS( MockUtilitaireHttp, UtilitaireHttp ) {
    MOCK_METHOD(executerGet, 1)
};

MOCK_BASE_CLASS(MockAnalyseurJson, AnalyseurJson) {
    MOCK_METHOD(extraireResultat, 1)
};


BOOST_AUTO_TEST_CASE(test_executer) {
    MockUtilitaireHttp utilitaire;
    MockAnalyseurJson analyseur;
    Executeur executeur(utilitaire, analyseur);
    Requete requete;
    requete.mutCible("devices");
    Resultat& attendu = *new Resultat();
    MOCK_EXPECT(utilitaire.executerGet).once().with("/1.1/devices").returns("{}");
    MOCK_EXPECT(analyseur.extraireResultat).once().with("{}").returns(attendu);

    executeur.executer(requete);
}
