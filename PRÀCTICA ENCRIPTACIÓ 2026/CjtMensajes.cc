#include "CjtMensajes.hh"

// Constructora

CjtMensajes::CjtMensajes() {
}

// Consultores

int CjtMensajes::size() const {
    return mensajes.size();
}

bool CjtMensajes::exists(const string& p) const {
    return mensajes.find(p) != mensajes.end();
}

// Modificadores

// Segons la Post, retorna cert si JA existia (és a dir, si no s'ha afegit).
// No toca el comptador de l'alfabet: ho fa el main amb alfabetos.inc(ida).
bool CjtMensajes::add(const string& p, const string& ida, const string& miss) {
    if (exists(p)) return true;
    mensajes[p] = Mensaje(ida, miss);
    return false;
}

// Retorna cert si existia (i s'ha esborrat). Retorna l'alfabet a ida perquè
// el main pugui fer alfabetos.dec(ida).
bool CjtMensajes::erase(const string& p, string& ida) {
    map<string, Mensaje>::iterator it = mensajes.find(p);
    if (it == mensajes.end()) return false;
    ida = it->second.consultar_alfabeto();
    mensajes.erase(it);
    return true;
}

// Codificar y decodificar: PENDENT

void CjtMensajes::encriptar(const string& /*idm*/, CjtAlfabetos& /*ca*/, const string& /*clave*/,
                            string& /*codif*/, bool& /*ok*/) const {
    // TODO: implementar aquí
    // Pre: si idm pertany al conjunt de missatges, llavors l'alfabet pertany
    //      al conjunt d'alfabets ca, i clave està escrita amb el mateix alfabet
    //      que el missatge
    // Post: si idm és un missatge del conjunt de missatges llavors ok == true,
    //       codif és la codificació per substitució del missatge d'id idm amb
    //       clau clave, i l'alfabet d'interès de ca passa a ser l'alfabet d'idm;
    //       si idm no és un missatge del conjunt llavors ok == false
}

void CjtMensajes::encriptar(const string& /*idm*/, int /*b*/, string& /*codif*/, bool& /*ok*/) const {
    // TODO: implementar aquí
    // Pre: b > 0
    // Post: si idm és un missatge del conjunt de missatges llavors ok == true
    //       i codif és la codificació per permutació del missatge d'id idm en
    //       blocs de mida b; altrament ok == false
}

// Entrada/sortida

void CjtMensajes::read(CjtAlfabetos& ca) {
    int n_mensajes;
    cin >> n_mensajes;
    for (int i = 0; i < n_mensajes; ++i) {
        string idm;
        cin >> idm;
        Mensaje mensaje;
        mensaje.read();
        ca.inc(mensaje.consultar_alfabeto());   // un missatge més amb aquest alfabet
        mensajes[idm] = mensaje;
    }
}

void CjtMensajes::print() const {
    int i = 1;
    map<string, Mensaje>::const_iterator it;
    for (it = mensajes.begin(); it != mensajes.end(); ++it) {
        // Format: "i. identificador", l'alfabet i el text entre cometes
        cout << i << ". " << it->first << endl;
        it->second.print();
        cout << endl;
        ++i;
    }
}
