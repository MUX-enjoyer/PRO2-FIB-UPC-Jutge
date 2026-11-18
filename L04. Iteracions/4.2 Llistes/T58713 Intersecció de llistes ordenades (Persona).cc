#include <list>
#include "persona.hh"
using namespace std;

/**
 * @brief Calcula la intersecció de dues llistes ordenades.
 *
 * @param a Llista en ordre ascendent de DNI.
 * @param b Llista en ordre ascendent de DNI.
 *
 * @return Llista en ordre ascendent de DNI amb les persones comunes d'a i b.
 */
list<Persona> interseccio_ordenada(const list<Persona>& a, const list<Persona>& b) {
    list<Persona> res;
    list<Persona>::const_iterator ia = a.begin();
    list<Persona>::const_iterator ib = b.begin();
    // Quan una de les dues llistes s'acaba ja no hi pot haver més comuns,
    // així no visitem elements innecessàriament
    while (ia != a.end() and ib != b.end()) {
        if (ia->dni() < ib->dni()) ++ia;
        else if (ib->dni() < ia->dni()) ++ib;
        else {
            res.push_back(*ia);
            ++ia;
            ++ib;
        }
    }
    return res;
}
