#ifndef _CJT_MENSAJES
#define _CJT_MENSAJES
#include <string>
#include <map>

#include "Mensaje.hh"
#include "CjtAlfabetos.hh"

using namespace std;

// -------------------------------------------------------------------------------
// CjtMensajes
// -------------------------------------------------------------------------------
//
// Es tracta d'un diccionari en que la clau és l'identificador i el
// valor és el missatge.

class CjtMensajes {
private:
      // La clau és l'identificador del missatge; el map ja els manté
      // ordenats per al llistat (listar_mensajes).
      map<string, Mensaje> mensajes;

public:

// Constructora

/** Ctor por defecto
      Pre: cert
      Post: crea un conjunt de missatges buit
*/   
CjtMensajes();

// Consultores

/** 
      Pre: cert
      Post: El resultat és el nombre de missatges del conjunt de missatges
*/
int size() const;

/** 
      Pre: cert
      Post: El resultat indica si existeix un missatge al conjunt amb l'identificador p
*/
bool exists(const string &p) const;

// Modificadores

/** 
      Pre: cert
      Post: El resultat indica si existia o no un missatge al conjunt amb l'identificador p; si no existia, s'ha afegit alconjunt un missatge amb 
      identificador p, alfabet ida i contingut miss
*/
bool add(const string& p,  const string& ida, const string& miss);

/** 
      Pre: cert
      Post: El resultat indica si existia o no un missatge al conjunt amb identificador p; si existia, 
      s'ha esborrat del conjunt i  ida n'es l'alfabet  
*/ 
bool erase(const string& p, string& ida);


// Codificar y decodificar
  
/** 
      Pre: si idm pertany al conjunt de missatges, llavors l'alfabet pertany
      al conjunt d'alfabets ca, i clave
      està escrita amb el mateix alfabet que el missatge 

      Post:  si idm és un missatge del conjunt de missatges llavors ok == true,
      codif es la codificació per substitució del missatge d'id idm
      amb clau clave, i l'alfabet d'interes de ca passa a ser 
      l'alfabet d'idm; si idm no és un missatge del conjunt llavors ok == false
*/ 
  void encriptar (const string& idm, CjtAlfabetos& ca, const string& clave, string& codif, bool& ok) const;

/** 
      Pre: b > 0
      Post:  si idm és un missatge del conjunt de missatges
      llavors ok == true i codif és la codificació per permutació
      del missatge d'id idm en blocs de mida b; altrament, si idm no és
      l'identificador d'un missatge existent llavors ok == false
*/ 
  void encriptar (const string& idm, int b, string& codif, bool& ok) const;


  
// Entrada/sortida

/** Lectura d'un conjunt de missatges
      Pre: El canal estàndar d'entrada conté un enter P seguit de P parells (identificador, missatge), on
           els identificadors són strings no repetits i els missatges estan formats per una única línia de caracters ASCII
           entre 32 i 126; el conjunt de missatges és buit
      Post: El conjunt de missatges conté un conjunt de P missatges amb els identificadors i continguts llegits; wl conjunt
      d'alfabets ca rep els increments 
      del nombre de missatges per cada alfabet implicat
*/
void read(CjtAlfabetos& ca);

/** 
      Pre: cert
      Post: S'ha escrit l'identificador i el contingut de tots els missatges del conjunt de missatges implícit pel canal estàndar de sortida 
      en ordre creixent per identificador <em>p</em>
*/
void print() const;

};
#endif
