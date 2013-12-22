#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include "../main/Resultat.hpp"
#include "../main/Afficheur.hpp"

using namespace std;

BOOST_AUTO_TEST_SUITE( test_afficheur )

struct redirection_cout {
    redirection_cout( std::streambuf * nveau_tampon )
        : tampon( std::cout.rdbuf( nveau_tampon ) )
    { }

    ~redirection_cout( ) {
        std::cout.rdbuf( tampon );
    }

private:
    std::streambuf * tampon;
};

BOOST_AUTO_TEST_CASE( test_afficher_resultat )
{
    boost::test_tools::output_test_stream sortie;
    {
        redirection_cout redir( sortie.rdbuf( ) );
        string colonnes[] = {"col1", "col2", "col3"};
        list<string>& projection = *new list<string>(colonnes, colonnes + sizeof(colonnes)/sizeof(colonnes[0]));
        map<string, string> tuple1;
        tuple1.insert(make_pair("col1", "val01"));
        tuple1.insert(make_pair("col3", "val03"));
        tuple1.insert(make_pair("col4", "val04"));
        map<string, string> tuple2;
        tuple2.insert(make_pair("col1", "val11"));
        tuple2.insert(make_pair("col2", "val12"));
        list<map<string, string> > tuples;
        tuples.push_back(tuple1);
        tuples.push_back(tuple2);
        Resultat& resultat = *new Resultat();
        resultat.mutTuples(tuples);

        Afficheur afficheur;
        afficheur.afficher(resultat, projection);
    }
    string attendu =
            "col1,col2,col3\n"
            "val01,,val03\n"
            "val11,val12,\n";
    BOOST_CHECK( sortie.is_equal( attendu ) );
}

BOOST_AUTO_TEST_SUITE_END()
