#include "bintree.hh"
using namespace pro2;

// Retorna cert si m és múltiple de n, és a dir, m = n*k amb k >= 1
bool es_multiple(int m, int n) {
    if (n == 0) return m == 0;
    return m >= n and m % n == 0;
}

/**
 * @brief Determina si un arbre és "de múltiples"
 *
 * @param  t  Un arbre binari de naturals
 *
 * @returns  `true` si `t` és un arbre de múltiples
 *           `false` altrament.
 */
bool arbre_de_multiples(BinTree<int> t) {
    if (t.empty()) return true;
    int n = t.value();
    BinTree<int> e = t.left();
    BinTree<int> d = t.right();
    // L'arrel de cada fill (si no és buit) ha de ser múltiple de l'arrel
    if (not e.empty() and not es_multiple(e.value(), n)) return false;
    if (not d.empty() and not es_multiple(d.value(), n)) return false;
    // I els dos subarbres també han de ser de múltiples
    return arbre_de_multiples(e) and arbre_de_multiples(d);
}
