#include <string>
#include <curl/curl.h>

#ifndef UTILITAIREHTTP_HPP_
#define UTILITAIREHTTP_HPP_

using namespace std;

class Rappel {
private:
    string contenu;
public:
    Rappel();
    void operator()(const char* tampon, size_t taille, size_t nb_membres, void* pointeur);
    string& accContenu();
};

class UtilitaireHttp {
private:
    string baseUrl;
    CURL* curl;
    Rappel& rappel;
public:
    UtilitaireHttp(string serveur, string port);
    virtual ~UtilitaireHttp();
    string& executerGet(string url);
};


#endif
