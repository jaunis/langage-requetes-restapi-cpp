#include "UtilitaireHttp.hpp"
#include <stddef.h>
#include <iostream>
#include <string>

size_t function( char *ptr, size_t size, size_t nmemb, Conteneur *conteneur) {
    conteneur->ajouter(*new string(ptr));
    return size * nmemb;
}


UtilitaireHttp::UtilitaireHttp(string serveur, string port): conteneur(*new Conteneur()) {
    baseUrl = string("http://").append(serveur).append(":").append(port).append("/1.1/");
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &conteneur);
}

UtilitaireHttp::UtilitaireHttp(): conteneur(*new Conteneur()) {}

UtilitaireHttp::~UtilitaireHttp() {}

string& UtilitaireHttp::executerGet(string url) {
    curl_easy_setopt(curl, CURLOPT_URL, baseUrl.append(url).c_str());
    curl_easy_perform(curl);
    return conteneur.accContenu();
}

Conteneur::Conteneur() {
    contenu = "";
}

string& Conteneur::accContenu() {
    return contenu;
}

void Conteneur::ajouter(string& s) {
    contenu = contenu.append(s);
}
