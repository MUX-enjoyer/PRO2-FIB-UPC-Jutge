#ifndef _MENSAJE
#define _MENSAJE

#include <string>

#include "CjtAlfabetos.hh"
#include "BinTree.hh"

using namespace std;

// -------------------------------------------------------------------------------
// Mensaje
// -------------------------------------------------------------------------------
//
// Es tracta d'un text representat per una string i l'identificador
// de l'alfabet

class Mensaje {
private:
      // Només guardem l'identificador de l'alfabet (no una còpia de l'Alfabeto):
      // l'alfabet real és al CjtAlfabetos i així no tenim dades duplicades.
      // "" vol dir alfabet buit (constructora Mensaje(s)).
      string ida;
      string texto;

public:

// Constructores

/** 
      Pre: cert
      Post: crea un missatge buit
*/   
  Mensaje();

/**  
      Pre: cert
      Post: crea un missatge amb text s i alfabet buit (Alfabeto())  
*/   
  Mensaje(const string& s);

/** 
      Pre: s està escrit amb l'alfabet a
      Post: crea un missatge amb text s i alfabet a 
*/   
  Mensaje(const string& a, const string& s);

  
// Consultores

/** 
      Pre: <em>cert</em>
      Post: El resultat és l'alfabet del missatge implícit
*/
  string consultar_alfabeto() const;


// Codif & decodif

/** 
      Pre: l'alfabet del missatge hi és al conjunt d'alfabets ca  i clave està escrit al mateix
      Post: codif és el resultat de codificar el missatge per substitució amb clau clave; l'"alfabetd'interes" de ca passa a ser l'alfabet del 
      missatge implícit
*/ 
  void encriptar(CjtAlfabetos& ca, const string& clave, string& codif) const;

/** 
      Pre: b>0
      Post: codif és el resultat de codificar el missatge per permutació amb mida bloc b
*/ 
  void encriptar(int b, string& codif) const;


/** 
      Pre: l'alfabet del missatge hi és al conjunt ca  i clave està escrit al mateix
      Post: <em>decodif</em> és el resultat de decodificar el p.i. per substitució amb clau <em>clave</em>; el punt d'interes de ca passa a ser l'alfabet del p.i.
*/ 
  void desencriptar(CjtAlfabetos& ca, const string& clave, string& decodif) const;
      
/** 
      Pre: <em>b>0</em>
      Post: <em>decodif</em> és el resultat de decodificar el p.i. per permutació amb mida bloc <em>b</em>
*/ 
  void desencriptar(int b, string& decodif) const;
 
// Entrada/sortida

/** 
      Pre: El canal estàndar d'entrada conté un parell (id alf, missatge), on
           el missatge està format per caracters ASCII
           entre 32 i 126; el p.i. és buit
      Post: El p.i. conté un missatge amb els identificadors i continguts llegits
*/
void read();

/** 
      Pre: <em>cert</em>
      Post: S'ha escrit l'alfabet i el text del p.i.
*/
void print() const;

};
#endif
