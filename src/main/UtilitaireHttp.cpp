#include "UtilitaireHttp.hpp"

UtilitaireHttp::UtilitaireHttp(string serveur, string port): rappel(*new Rappel()) {
    baseUrl = string("http://").append(serveur).append(":").append(port).append("/");
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &rappel);
}

UtilitaireHttp::~UtilitaireHttp() {}

string& UtilitaireHttp::executerGet(string url) {
    curl_easy_setopt(curl, CURLOPT_URL, baseUrl.append("/").append(url).c_str());
    curl_easy_perform(curl);
    return rappel.accContenu();
}

Rappel::Rappel() {
    contenu = "";
}

void Rappel::operator ()(const char* tampon, size_t taille, size_t nb_membres, void* pointeur) {
    contenu = contenu.append(tampon, nb_membres);
}

string& Rappel::accContenu() {
    return contenu;
}