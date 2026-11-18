#include "Mensaje.hh"
#include <iostream>

// Constructores

Mensaje::Mensaje() {
    ida = "";
    texto = "";
}

Mensaje::Mensaje(const string& s) {
    ida = "";      // alfabet buit (Alfabeto()), veure aclariments 16/11
    texto = s;
}

Mensaje::Mensaje(const string& a, const string& s) {
    ida = a;
    texto = s;
}

// Consultores

string Mensaje::consultar_alfabeto() const {
    return ida;
}

// Codif & decodif: PENDENT
// (paràmetres comentats perquè amb -Wextra -Werror un paràmetre no usat
//  és un error de compilació)

void Mensaje::encriptar(CjtAlfabetos& /*ca*/, const string& /*clave*/, string& /*codif*/) const {
    // TODO: implementar aquí
    // Pre: l'alfabet del missatge hi és al conjunt d'alfabets ca i clave està
    //      escrit al mateix
    // Post: codif és el resultat de codificar el missatge per substitució amb
    //       clau clave; l'"alfabet d'interès" de ca passa a ser l'alfabet del
    //       missatge implícit
}

void Mensaje::encriptar(int /*b*/, string& /*codif*/) const {
    // TODO: implementar aquí
    // Pre: b > 0
    // Post: codif és el resultat de codificar el missatge per permutació amb
    //       mida bloc b
}

void Mensaje::desencriptar(CjtAlfabetos& /*ca*/, const string& /*clave*/, string& /*decodif*/) const {
    // TODO: implementar aquí
    // Pre: l'alfabet del missatge hi és al conjunt ca i clave està escrit al mateix
    // Post: decodif és el resultat de decodificar el p.i. per substitució amb
    //       clau clave; el punt d'interès de ca passa a ser l'alfabet del p.i.
}

void Mensaje::desencriptar(int /*b*/, string& /*decodif*/) const {
    // TODO: implementar aquí
    // Pre: b > 0
    // Post: decodif és el resultat de decodificar el p.i. per permutació amb
    //       mida bloc b
}

// Entrada/sortida

void Mensaje::read() {
    cin >> ida;
    // El text té espais, per això no es pot llegir amb cin >>.
    // El primer getline acaba la línia de l'identificador i el segon llegeix
    // el text del missatge.
    string resta;
    getline(cin, resta);
    getline(cin, texto);
}

void Mensaje::print() const {
    cout << ida << endl;
    cout << "\"" << texto << "\"";
}
