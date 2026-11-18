#ifndef _CJT_ALFABETOS
#define _CJT_ALFABETOS
#include <string>
#include <map>
#include "Alfabeto.hh"


using namespace std;

// -------------------------------------------------------------------------------
// CjtAlfabetos
// -------------------------------------------------------------------------------
//
// Es tracta d'un diccionari en que la clau és l'identificador i el
// valor és l'alfabet

class CjtAlfabetos {
private:
      // Implementació provisional (fase 2) amb un map de la STL: la clau és
      // l'identificador i el map ja els manté ordenats per al llistat.
      // A la versió final s'ha de fer amb memòria dinàmica i sense STL.
      map<string, Alfabeto> alfabetos;

      // Identificador de l'"alfabet d'interès": el fixa set_alf i és el que
      // faran servir encriptar/desencriptar (que només reben dos caràcters).
      string alf_interes;

public:

// Constructores, dtor i assignació

/** ctor por defecto
      Pre: cert
      Post: crea un conjunt d'alfabets buit
*/   
  CjtAlfabetos();

  /** copy ctor 
      Pre: cert
      Post: crea un conjunt d'alfabets com a còpia del conjunt ca
*/   
  CjtAlfabetos(const CjtAlfabetos& ca);

/** 
      Pre: cert
      Post: destrueix el conjunt d'alfabets implícit 
*/
~CjtAlfabetos();

/** 
      Pre:
      Post: el conjunt implícit té els mateixos continguts que ca
*/
CjtAlfabetos& operator=(const CjtAlfabetos& ca);

// Consultores

/** 
      Pre: cert
      Post: Retorna el nombre d'alfabets que conté el conjunt d'alfabets
*/
int size() const;

/** 
      Pre: cert
      Post: Retorna cert ssi el conjunt d'alfabets conté un alfabet amb l'identificador p
*/
bool exists(const string &p) const;

/** 
      Pre: tant t com c pertanyen a l'"alfabet d'interès" 
      Post: retorna el resultat de codificar per substitucio el caracter t amb el caracter c d'una clau, com a membres 
      de l'"alfabet d'interès"
*/ 
  char encriptar (char t, char c) const;

/** 
      Pre: tant t com c pertanyen a l'"alfabet d'interès"
      Post: retorna el resultat de decodificar per substitucio el caracter t amb el caracter c d'una clau, com a membres 
      de l'"alfabet d'interès"
*/ 
  char desencriptar(char t, char c) const;
  
// Modificadores

/**
      Pre: cert
      Post: Retorna certo o fals segons si existia o no un alfabet amb l'identificador p al conjunt d'alfabets; 
      si no existia, s'ha afegit al conjunt d'alfabets un alfabet amb identificador p i contingut alf
*/
bool add(const string &p, const string& alf);

/** 
      Pre: cert
      Post: hi_es indica si existia un alfabet al conjunt d'alafabets amb identificador p; si és cert, te_missatges indica si tenia algún missatge; 
      si existia i no tenia cap missatge, s'ha esborrat del conjunt d'alfabets
*/ 
  void erase(const string &p, bool& hi_es, bool& te_missatges);

/** 
      Pre: alf és un alfabet del conjunt d'alfabets
      Post: el nombre de missatges d'alf s'incrementa en un
*/ 
  void inc (const string& alf);
    
/** 
      Pre: alf és un alfabet del conjunt d'alfabets
      Post: el nombre de missatges d'alf es decrementa en un
*/
void dec (const string& alf);

/**
      Pre:  cert
      Post: l'alfabet amb identificador alf es converteix en l'"alfabet d'interès"
 */  
void set_alf(const string& alf);
  
  // Entrada/sortida

  /** Operació de lectura del conjunt d'alfabets
      Pre: El canal estàndar d'entrada conté un enter P >= 0, seguit de P parells (identificador, alfabet), on
           els identificadors són strings no repetits i els alfabets estan formats per una única línia de caracters ASCII
           entre 32 i 126; el conjunt d'alfabets és buit
      Post: El conjunt d'alfabets conté un conjunt de P alfabets amb els identificadors i continguts llegits

*/
void read();

 /** Operació d'escriptura del conjunt d'alfabets per ordre alfabètic d'identificador
      Pre: cert
      Post: S'ha escrit l'identificador <em>p</em> i el contingut de tots els alfabets del p.i. pel canal estàndar de sortida en ordre creixent per identificador <em>p</em>
*/
void print() const;
};
#endif
