#include <string>
#include <curl/curl.h>

#ifndef UTILITAIREHTTP_HPP_
#define UTILITAIREHTTP_HPP_

using namespace std;


class Conteneur {
private:
    string contenu;
public:
    Conteneur();
    string& accContenu();
    void ajouter(string& s);
};

extern "C" {
    size_t function( char *ptr, size_t size, size_t nmemb, Conteneur *userdata);
}

class UtilitaireHttp {
private:
    string baseUrl;
    CURL* curl;
    Conteneur& conteneur;
protected:
    UtilitaireHttp();
public:
    UtilitaireHttp(string serveur, string port);
    virtual ~UtilitaireHttp();
    virtual string& executerGet(string url);
};


#endif
