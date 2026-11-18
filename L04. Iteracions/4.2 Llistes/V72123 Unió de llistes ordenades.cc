#include <list>
#include "person.hh"
using namespace std;

/**
 * @brief Uneix dues llistes ordenades preservant l'ordre.
 *
 * Si hi ha persones que apareixen a les dues llistes, només
 * han d'aparèixer un cop al resultat.
 *
 * @param a Llista ordenada de persones.
 * @param b Llista ordenada de persones.
 *
 * @return Llista ordenada amb els elements d'a i b sense repetits.
 */
list<Person> unio_ordenada(const list<Person>& a, const list<Person>& b) {
    list<Person> res;
    list<Person>::const_iterator ia = a.begin();
    list<Person>::const_iterator ib = b.begin();
    while (ia != a.end() and ib != b.end()) {
        if (ia->is_less_than(*ib)) {
            res.push_back(*ia);
            ++ia;
        }
        else if (ib->is_less_than(*ia)) {
            res.push_back(*ib);
            ++ib;
        }
        else {
            // És la mateixa persona: només n'afegim una còpia
            res.push_back(*ia);
            ++ia;
            ++ib;
        }
    }
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
