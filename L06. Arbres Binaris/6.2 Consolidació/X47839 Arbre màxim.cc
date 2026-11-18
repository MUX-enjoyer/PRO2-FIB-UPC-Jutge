// Fa servir la classe BinTree antiga (BinTree.hh dels fitxers públics del problema)
#include "BinTree.hh"

// Pre: Rep dos arbres binaris d'enters positius t1 i t2.
// Post: Retorna un arbre on cada posició té el màxim dels valors de t1 i t2
//       en aquella posició; si un dels dos no hi té valor, s'agafa el de l'altre.
BinTree<int> maximumTree(BinTree<int> t1, BinTree<int> t2) {
    // Si un dels dos és buit, en aquesta posició (i a sota) queda l'altre
    if (t1.empty()) return t2;
    if (t2.empty()) return t1;
    int maxim = t1.value();
    if (t2.value() > maxim) maxim = t2.value();
    return BinTree<int>(maxim, maximumTree(t1.left(), t2.left()),
                               maximumTree(t1.right(), t2.right()));
}
