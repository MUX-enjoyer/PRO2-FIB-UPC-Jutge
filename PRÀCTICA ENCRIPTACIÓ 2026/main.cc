#include <iostream>
#include <string>
using namespace std;

#include "Mensaje.hh"
#include "CjtMensajes.hh"
#include "CjtAlfabetos.hh"

// Llegeix la línia següent sencera. Només es fa servir per a missatges,
// alfabets i claus, perquè poden tenir espais i cin >> s'atura al primer
// espai. Tota la resta (comandes, identificadors, números) es llegeix amb cin >>.
// El primer getline acaba la línia actual (després d'un cin >> encara hi queda
// el salt de línia) i el segon llegeix la línia que volem.
string llegir_linia() {
    string resta, linia;
    getline(cin, resta);
    getline(cin, linia);
    return linia;
}

void procesa_nuevo_mensaje(const string& op, CjtMensajes& mensajes, CjtAlfabetos& alfabetos) {
    string idm, ida;
    cin >> idm >> ida;
    // El text s'ha de llegir sempre, encara que hi hagi error,
    // perquè si no el següent cin >> op el llegiria com a comanda
    string texto = llegir_linia();
    cout << "#" << op << " " << idm << " " << ida << endl;
    if (not alfabetos.exists(ida)) {
        cout << "error: el alfabeto no existe" << endl;
    }
    else if (mensajes.add(idm, ida, texto)) {
        cout << "error: ya existe un mensaje con ese identificador" << endl;
    }
    else {
        alfabetos.inc(ida);
        cout << mensajes.size() << endl;
    }
}

void procesa_nuevo_alfabeto(const string& op, CjtAlfabetos& alfabetos) {
    string ida;
    cin >> ida;
    string contenido = llegir_linia();
    cout << "#" << op << " " << ida << endl;
    if (alfabetos.add(ida, contenido)) cout << "error: el alfabeto ya existe" << endl;
    else cout << alfabetos.size() << endl;
}

void procesa_borra_mensaje(const string& op, CjtMensajes& mensajes, CjtAlfabetos& alfabetos) {
    string idm;
    cin >> idm;
    cout << "#" << op << " " << idm << endl;
    string ida;
    if (mensajes.erase(idm, ida)) {
        alfabetos.dec(ida);   // l'alfabet té un missatge menys
        cout << mensajes.size() << endl;
    }
    else {
        cout << "error: el mensaje no existe" << endl;
    }
}

void procesa_borra_alfabeto(const string& op, CjtAlfabetos& alfabetos) {
    string ida;
    cin >> ida;
    cout << "#" << op << " " << ida << endl;
    bool hi_es, te_missatges;
    alfabetos.erase(ida, hi_es, te_missatges);
    if (not hi_es) cout << "error: el alfabeto no existe" << endl;
    else if (te_missatges) cout << "error: hay mensajes guardados con el alfabeto" << endl;
    else cout << alfabetos.size() << endl;
}

void procesa_listar_mensajes(const string& op, const CjtMensajes& mensajes) {
    cout << "#" << op << endl;
    mensajes.print();
}

void procesa_listar_alfabetos(const string& op, const CjtAlfabetos& alfabetos) {
    cout << "#" << op << endl;
    alfabetos.print();
}

// ---------------------------------------------------------------------------
// Funcionalitats PENDENTS (codificació / decodificació)
// Ja llegeixen tota l'entrada, escriuen la capçalera i els errors;
// falta cridar l'encriptació i escriure el resultat entre cometes:
//     cout << "\"" << resultat << "\"" << endl;
// ---------------------------------------------------------------------------

void procesa_codificar_sustitucion_guardado(const string& op, const CjtMensajes& mensajes) {
    string idm;
    cin >> idm;
    string clave = llegir_linia();
    cout << "#" << op << " " << idm << " \"" << clave << "\"" << endl;
    if (not mensajes.exists(idm)) {
        cout << "error: el mensaje no existe" << endl;
    }
    else {
        // TODO: mensajes.encriptar(idm, alfabetos, clave, codif, ok) i escriure codif
    }
}

void procesa_codificar_sustitucion(const string& op, const CjtAlfabetos& alfabetos) {
    string ida;
    cin >> ida;
    string clave = llegir_linia();
    string texto;
    getline(cin, texto);   // el missatge és a la línia següent a la clau
    cout << "#" << op << " " << ida << " \"" << clave << "\"" << endl;
    if (not alfabetos.exists(ida)) {
        cout << "error: el alfabeto no existe" << endl;
    }
    else {
        // TODO: crear Mensaje(ida, texto), encriptar(alfabetos, clave, codif) i escriure codif
    }
}

void procesa_decodificar_sustitucion(const string& op, const CjtAlfabetos& alfabetos) {
    string ida;
    cin >> ida;
    string clave = llegir_linia();
    string texto;
    getline(cin, texto);
    cout << "#" << op << " " << ida << " \"" << clave << "\"" << endl;
    if (not alfabetos.exists(ida)) {
        cout << "error: el alfabeto no existe" << endl;
    }
    else {
        // TODO: crear Mensaje(ida, texto), desencriptar(alfabetos, clave, decodif) i escriure decodif
    }
}

void procesa_codificar_permutacion_guardado(const string& op, const CjtMensajes& mensajes) {
    string idm;
    int b;
    cin >> idm >> b;
    cout << "#" << op << " " << idm << " " << b << endl;
    if (not mensajes.exists(idm)) {
        cout << "error: el mensaje no existe" << endl;
    }
    else {
        // TODO: mensajes.encriptar(idm, b, codif, ok) i escriure codif
    }
}

// Aquests dos no tenen cap cas d'error
void procesa_codificar_permutacion(const string& op) {
    int b;
    cin >> b;
    string texto = llegir_linia();
    cout << "#" << op << " " << b << endl;
    // TODO: crear Mensaje(texto), encriptar(b, codif) i escriure codif
}

void procesa_decodificar_permutacion(const string& op) {
    int b;
    cin >> b;
    string texto = llegir_linia();
    cout << "#" << op << " " << b << endl;
    // TODO: crear Mensaje(texto), desencriptar(b, decodif) i escriure decodif
}

// Cada comanda té la versió llarga i l'abreujada
void procesa(const string& op, CjtMensajes& mensajes, CjtAlfabetos& alfabetos) {
    if (op == "nuevo_mensaje" or op == "nm") procesa_nuevo_mensaje(op, mensajes, alfabetos);
    else if (op == "nuevo_alfabeto" or op == "na") procesa_nuevo_alfabeto(op, alfabetos);
    else if (op == "borra_mensaje" or op == "bm") procesa_borra_mensaje(op, mensajes, alfabetos);
    else if (op == "borra_alfabeto" or op == "ba") procesa_borra_alfabeto(op, alfabetos);
    else if (op == "listar_mensajes" or op == "lm") procesa_listar_mensajes(op, mensajes);
    else if (op == "listar_alfabetos" or op == "la") procesa_listar_alfabetos(op, alfabetos);
    else if (op == "codificar_sustitucion_guardado" or op == "csg")
        procesa_codificar_sustitucion_guardado(op, mensajes);
    else if (op == "codificar_sustitucion" or op == "cs") procesa_codificar_sustitucion(op, alfabetos);
    else if (op == "decodificar_sustitucion" or op == "ds") procesa_decodificar_sustitucion(op, alfabetos);
    else if (op == "codificar_permutacion_guardado" or op == "cpg")
        procesa_codificar_permutacion_guardado(op, mensajes);
    else if (op == "codificar_permutacion" or op == "cp") procesa_codificar_permutacion(op);
    else if (op == "decodificar_permutacion" or op == "dp") procesa_decodificar_permutacion(op);
}

int main() {
    CjtAlfabetos alfabetos;
    alfabetos.read();

    CjtMensajes mensajes;
    mensajes.read(alfabetos);   // va incrementant el nombre de missatges de cada alfabet

    string op;
    cin >> op;
    while (op != "fin") {
        procesa(op, mensajes, alfabetos);
        cin >> op;
    }
}
