#include <list>
#include "fruit.hh"
using namespace std;

/**
 * @brief Fusiona dues llistes ordenades preservant l'ordre.
 *
 * @param a Llista en ordre descendent (pot contenir noms repetits).
 * @param b Llista en ordre descendent (pot contenir noms repetits).
 *
 * @return Llista en ordre descendent amb els elements d'a i b.
 */
list<Fruit> fusio_ordenada(const list<Fruit>& a, const list<Fruit>& b) {
    list<Fruit> res;
    list<Fruit>::const_iterator ia = a.begin();
    list<Fruit>::const_iterator ib = b.begin();
    // Mentre quedin elements a les dues, posem el més gran dels dos
    while (ia != a.end() and ib != b.end()) {
        if (ib->is_greater_than(*ia)) {
            res.push_back(*ib);
            ++ib;
        }
        else {
            res.push_back(*ia);
            ++ia;
        }
    }
    // Afegim el que quedi d'una de les dues llistes
    while (ia != a.end()) {
        res.push_back(*ia);
        ++ia;
    }
    while (ib != b.end()) {
        res.push_back(*ib);
        ++ib;
    }
    return res;
}
