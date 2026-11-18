#include <list>
using namespace std;

/**
 * @brief Ordena un rang d'una llista usant selecció.
 *
 * @param begin Iterador al principi del rang.
 * @param end Iterador al final del rang (no inclòs).
 * @pre begin i end delimiten un rang vàlid d'una llista.
 * @post El rang [begin, end) queda ordenat ascendentment.
 */
void ordenacio_seleccio(list<int>::iterator begin, list<int>::iterator end) {
    for (list<int>::iterator it = begin; it != end; ++it) {
        // Busquem el mínim del rang [it, end)
        list<int>::iterator minim = it;
        list<int>::iterator it2 = it;
        ++it2;
        while (it2 != end) {
            if (*it2 < *minim) minim = it2;
            ++it2;
        }
        // El posem a la primera posició de la part no ordenada
        swap(*it, *minim);
    }
}
