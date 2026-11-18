#include "CjtAlfabetos.hh"

// Constructores, dtor i assignació

CjtAlfabetos::CjtAlfabetos() {
    alf_interes = "";
}

CjtAlfabetos::CjtAlfabetos(const CjtAlfabetos& ca) {
    alfabetos = ca.alfabetos;
    alf_interes = ca.alf_interes;
}

CjtAlfabetos::~CjtAlfabetos() {
}

CjtAlfabetos& CjtAlfabetos::operator=(const CjtAlfabetos& ca) {
    if (this != &ca) {
        alfabetos = ca.alfabetos;
        alf_interes = ca.alf_interes;
    }
    return *this;
}

// Consultores

int CjtAlfabetos::size() const {
    return alfabetos.size();
}

bool CjtAlfabetos::exists(const string& p) const {
    return alfabetos.find(p) != alfabetos.end();
}

// Encriptació / desencriptació amb l'"alfabet d'interès": PENDENT

char CjtAlfabetos::encriptar(char t, char /*c*/) const {
    // TODO: implementar aquí
    // Pre: tant t com c pertanyen a l'"alfabet d'interès"
    // Post: retorna el resultat de codificar per substitucio el caracter t amb
    //       el caracter c d'una clau, com a membres de l'"alfabet d'interès"
    return t;
}

char CjtAlfabetos::desencriptar(char t, char /*c*/) const {
    // TODO: implementar aquí
    // Pre: tant t com c pertanyen a l'"alfabet d'interès"
    // Post: retorna el resultat de decodificar per substitucio el caracter t amb
    //       el caracter c d'una clau, com a membres de l'"alfabet d'interès"
    return t;
}

// Modificadores

// Segons la Post, retorna cert si JA existia (és a dir, si no s'ha afegit)
bool CjtAlfabetos::add(const string& p, const string& alf) {
    if (exists(p)) return true;
    alfabetos[p] = Alfabeto(alf);
    return false;
}

void CjtAlfabetos::erase(const string& p, bool& hi_es, bool& te_missatges) {
    map<string, Alfabeto>::iterator it = alfabetos.find(p);
    hi_es = (it != alfabetos.end());
    te_missatges = false;
    if (hi_es) {
        te_missatges = it->second.has_messages();
        if (not te_missatges) alfabetos.erase(it);
    }
}

// Pre: alf existeix (si no, l'operador [] del map el crearia buit)
void CjtAlfabetos::inc(const string& alf) {
    alfabetos[alf].inc();
}

void CjtAlfabetos::dec(const string& alf) {
    alfabetos[alf].dec();
}

void CjtAlfabetos::set_alf(const string& alf) {
    alf_interes = alf;
}

// Entrada/sortida

void CjtAlfabetos::read() {
    int n_alfabetos;
    cin >> n_alfabetos;
    for (int i = 0; i < n_alfabetos; ++i) {
        string ida;
        cin >> ida;
        Alfabeto alfabeto;
        alfabeto.read();   // llegeix la línia amb el contingut
        alfabetos[ida] = alfabeto;
    }
}

void CjtAlfabetos::print() const {
    int i = 1;
    map<string, Alfabeto>::const_iterator it;
    for (it = alfabetos.begin(); it != alfabetos.end(); ++it) {
        // Format: "i. identificador" i a la línia següent l'alfabet
        cout << i << ". " << it->first << endl;
        it->second.print();
        cout << endl;
        ++i;
    }
}
