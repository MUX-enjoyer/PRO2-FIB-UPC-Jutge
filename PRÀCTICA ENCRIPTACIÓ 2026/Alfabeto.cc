#include "Alfabeto.hh"

// Constructores

Alfabeto::Alfabeto() {
    caracteres = "";
    especial = false;
    n_mensajes = 0;
}

Alfabeto::Alfabeto(const string& a) {
    caracteres = a;
    especial = comprobar_especial();
    n_mensajes = 0;
}

// Consultores

bool Alfabeto::has_messages() const {
    return n_mensajes > 0;
}

// Encriptació / desencriptació per substitució: PENDENT
// (els noms dels paràmetres no usats van comentats perquè amb -Wextra -Werror
//  un paràmetre no utilitzat és un error de compilació)

char Alfabeto::encriptar(char t, char /*c*/) const {
    // TODO: implementar aquí
    // Pre: Tant t com c pertanyen a l'alfabet implícit
    // Post: retorna el resultat de codificar per substitució el caràcter t amb
    //       el caràcter c d'una clau, com a membres de l'alfabet
    return t;
}

char Alfabeto::desencriptar(char t, char /*c*/) const {
    // TODO: implementar aquí
    // Pre: Tant t com c pertanyen a l'alfabet implícit
    // Post: retorna el resultat de decodificar per substitució el caràcter t
    //       amb el caràcter c d'una clau, com a membres de l'alfabet
    return t;
}

// Modificadores

void Alfabeto::inc() {
    ++n_mensajes;
}

void Alfabeto::dec() {
    --n_mensajes;
}

// Entrada/sortida

// L'identificador el llegeix CjtAlfabetos::read (és la clau del map),
// aquí només llegim la línia amb el contingut de l'alfabet.
void Alfabeto::read() {
    // L'alfabet pot tenir espais (fins i tot al principi o al final, com
    // "minusculas" o "full_interv"), per això no es pot llegir amb cin >>.
    // El primer getline acaba la línia de l'identificador (després del
    // cin >> id encara hi queda el salt de línia) i el segon llegeix l'alfabet.
    string resta;
    getline(cin, resta);
    getline(cin, caracteres);
    especial = comprobar_especial();
    n_mensajes = 0;
}

void Alfabeto::print() const {
    if (especial) {
        // Un alfabet especial es mostra com a interval: [primer..últim]
        cout << "especial [" << caracteres[0] << ".." << caracteres[caracteres.size() - 1] << "]";
    }
    else {
        cout << "normal \"" << caracteres << "\"";
    }
    cout << " " << n_mensajes << " mensajes";
}

// Mètodes privats

bool Alfabeto::comprobar_especial() const {
    if (caracteres.empty()) return false;
    // Cada caràcter ha de ser el següent de l'anterior a la taula ASCII
    for (int i = 1; i < caracteres.size(); ++i) {
        if (caracteres[i] != caracteres[i - 1] + 1) return false;
    }
    return true;
}
