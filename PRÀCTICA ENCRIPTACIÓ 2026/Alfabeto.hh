#ifndef _ALFABETO
#define _ALFABETO
 
#include <string>
#include <iostream>

using namespace std;

// -------------------------------------------------------------------------------
// Alfabeto
// -------------------------------------------------------------------------------
//
// Es tracta d'un subconjunt ordenat de la taula ASCII (32-126)


class Alfabeto {
private:
      // Guardem l'alfabet com a string (i no com a set<char>) perquè l'ordre
      // dels caràcters importa: "abc" i "bca" són alfabets diferents.
      string caracteres;

      // Cert si caracteres és un interval consecutiu de la taula ASCII (p.ex. "abc").
      // Es calcula una sola vegada en crear/llegir l'alfabet perquè el print
      // (i més endavant l'encriptació) el necessiten sovint.
      bool especial;

      // Nombre de missatges guardats que fan servir aquest alfabet; cal per
      // saber si es pot esborrar (borra_alfabeto) i per llistar-lo.
      int n_mensajes;

      /** Pre: cert
          Post: retorna cert si caracteres és un interval consecutiu de la taula ASCII
      */
      bool comprobar_especial() const;

public:

/** Ctor por defecto
      Pre cert
      Post Crea un alfabet buit
*/
  Alfabeto();

/** 
      Pre a no conté caracters repetits
      Post Crea un alfabet amb els caracters d'a i 0 missatges
*/
  Alfabeto(const string& a);
  
/** 
      Pre cert
      Post El resultat indica si l'alfabet té o no algun missatge  
*/
  bool has_messages() const;


/** Encriptació per substitució
      Pre Tant t com c pertanyen a l'alfabet implícit
      Post retorna el resultat de codificar per substitució el caràcter t amb el caràcter c d'una clau, com a membres 
      de l'alfabet 
*/   
char encriptar(char t, char c) const;
    
/** Desencriptació per substitució
      Pre Tant t com c pertanyen a l'alafabet implícit
      Post retorna el resultat de decodificar per substitució el caràcter t amb el caràcter c d'una clau, com a membres 
      de l'alfabet
*/   
char desencriptar(char t, char c) const;
  
/** 
      Pre cert
      Post el nombre de missatges de l'alfabet s'incrementa en un
*/
void inc();


/** 
      Pre cert
      Post el nombre de missatges de l'alfabet es decrementa en un
*/
void dec();
  
  
// Entrada/sortida

/** Lectura d'un alfabet
    Pre El canal estàndar d'entrada conté un parell (identificador, alfabet), on
         l'alfabet està format per una única línia de caracters ASCII
           entre 32 i 126; l'alafabet és buit
    Post L'alfabet implícit és un alfabet amb l'identificador i contingut llegits

*/
void read();

/** Escriptura d'un alfabet
      Pre cert
      Post S'ha escrit l'alfabet impolícit pel canal estàndar de sortida
*/
void print() const;

};
#endif
