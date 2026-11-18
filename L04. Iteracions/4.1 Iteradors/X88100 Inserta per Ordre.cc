#include <list>
using namespace std;

/**
 * @brief Insereix un valor en una llista ordenada.
 *
 * @param l Llista d'enters ordenada ascendentment.
 * @param x Valor a inserir.
 * @pre l està ordenada ascendentment.
 * @post l conté x i segueix ordenada ascendentment.
 */
void inserta_per_ordre(list<int>& l, int x) {
    // Avancem fins al primer element que no sigui menor que x
    list<int>::iterator it = l.begin();
    while (it != l.end() and *it < x) ++it;
    // insert posa x just abans de l'element apuntat per it
    l.insert(it, x);
}
